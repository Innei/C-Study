
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char token;

double expe(void);
double term(void);
double factor(void);
char getPrintableChar(void);

void match(char expectedToken);
void error(void);

int main(void)
{
    double result;

    for (;;)
    {
        token = getPrintableChar();
        if (token == 'q')
            break;

        result = expe();
        if (token == '\n')
            printf("Result is: %g\n", result);
        else
            error();
    }

    return 0;
}

double expe(void)
{
    double temp = term();
    while (token == '+' || token == '-')
        switch (token)
        {
        case '+':
            match('+');
            temp += term();
            break;
        case '-':
            match('-');
            temp -= term();
            break;
        }
    return temp;
}

double term(void)
{
    double temp = factor();
    while (token == '*' || token == '/')
        switch (token)
        {
        case '*':
            match('*');
            temp *= factor();
            break;
        case '/':
            match('/');
            temp /= factor();
            break;
        }
    return temp;
}

double factor(void)
{
    double temp;
    if (token == '(')
    {
        match('(');
        temp = expe();
        match(')');
    }
    else if (isdigit(token))
    {
        ungetc(token, stdin);
        scanf("%lf", &temp);
        token = getPrintableChar();
    }
    else
        error();

    return temp;
}

void error(void)
{
    fprintf(stderr, "Error!\n");
    exit(EXIT_FAILURE);
}

void match(char expectedToken)
{
    if (expectedToken == token)
        token = getPrintableChar();
    else
        error();
}

char getPrintableChar(void)
{
    char temp;
    do
        temp = getchar();
    while (isblank(temp));

    return temp;
}
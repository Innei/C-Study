#include <stdio.h>
// 1个字节(8位)一个地址
struct Student 
{
    char name[6];
    int age;
    char sex[4];
};
void InputStudent(struct Student *pS)  // 修改变量才需要指针 
{
    pS->age = 10;
    strcpy(pS->name, "yiny");

}
void OutputStudent(struct Student *ss)  // 此处使用指针来传递的好处 : 只传递首个地址,而不是内容 效率高 内存占用小
{
    printf("%s\t%d\n",ss->name, ss->age);
}
int main(int argc, char const *argv[])
{
    struct Student st;
    InputStudent(&st);
   // printf("%s\t%d\n",st.name, st.age);
    OutputStudent(&st);
    return 0;
}


//
//  main.cpp
//  字符串中数字子串的求和
//
//  Created by zjl on 16/8/13.
//  Copyright © 2016年 zjl. All rights reserved.
//  for example:
//  A-1BC--12    the number is -1,12 and the sum is 11
 
#include <iostream>
#include <string>
using namespace std;
 
bool isdigits(char c){ //判断字符是否是数字
    if(c < '9' && c > '0')
        return true;
    else
        return false;
}
 
 
int solve(string s){
    if(s.size() == 0) return 0;
    int sum = 0, count = 0, sum_part = 0;
    bool isdigit = false; //判断是否有数字存在
    int i = 0;
    while( i < s.size()){
        isdigit = false;
        while(i < s.size() && s[i] == '-'){ //累计符号的数量
            count++;
            i++;
        }
        while(i < s.size() && isdigits(s[i])){ //若是数字，则统计局部和
            isdigit = true;
            sum_part = sum_part * 10 + (s[i] - '0');
            i++;
        }
        if(isdigit){  //若前面是数字，则将其加到总和上去
            if(count % 2 == 1)
                sum_part *= -1;
            sum += sum_part;
            sum_part = 0;
        }
        count = 0;
        ++i;
    }
    return sum;
}
 
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "A1BC--2C--D6E";
    int sum = solve(s);
    cout<<sum<<endl;
    return 0;
}

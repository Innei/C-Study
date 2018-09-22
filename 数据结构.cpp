#include <iostream>
using namespace std;
struct students
{
	char name[10];
	int age;
	char sex;
	float num;
};

int main() {
	struct students mine = {"yiny", 18, 'F'};
	cout << mine.name << endl;
	cout << mine.age << endl;
	struct students test;
	//test.name[3] = "li"; //error
	  					   //字符串不能用=赋值
	strcpy(test.name, "yinyyyyyyy");
	test.sex = 'F';

	//point
	struct students *p = &test;
	cout << p << endl;
	//cout << p+1 << endl;
	//cout << *p << endl; error
	p->age = 18; // 等价于 (*p).age 也等价于 test.age
	//cout << test << endl;
	p->num = 66.6f;
	cout << p->num << endl;
	
	return 0;
}

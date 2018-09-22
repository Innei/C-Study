#include <iostream>
using namespace std;
struct students
{
	char name[10];
	int age;
	char sex;
};

int main() {
	struct students mine = {"yiny", 18, 'F'};
	cout << mine.name << endl;
	cout << mine.age << endl;


	return 0;

}

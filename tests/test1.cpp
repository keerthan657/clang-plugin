#include <iostream>
using namespace std;

int add(int a, int b) {
	return a+b;
}
int sub(int *a, int *b) {
	return *a-*b;
}
void noret1_ptr(string *str) {
	cout << "String 1: " << str << endl;
	return;
}
void noret1_val(string str) {
	str = "changed";		// VVVIMP!!!!!
	cout << "String 2: " << str << endl;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x=3, y=4;
	std::cout << "ADD result: " << add(x,y) << endl;
	std::cout << "SUB result: " << sub(&x,&y) << endl;

	string s1 = "hello";
	noret1_ptr(&s1);
	noret1_val(s1);

	swap(&x, &y);
	std::cout << "Swapping... DONE!";

	return 0;
}
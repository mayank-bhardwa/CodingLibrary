#include <iostream>
using namespace std;

void print()
{
	cout<<"Hello\n";
	print();
}

int main()
{
	print();
	return 0;
}
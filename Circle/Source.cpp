#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	double r = 5;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r ; j++) cout << "  ";
		for (int j = i; j < r ; j++) cout << "* ";
		cout << endl;
	}
}
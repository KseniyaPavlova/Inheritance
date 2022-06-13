#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	std::ofstream fout;		//1) Создаем поток
	fout.open("File.txt", std::ios_base::app);	//2) Открываем поток
	fout << "Hello World!\n"; //3) Выводим поток
	fout.close();			//4) Закрываем поток
	//Потоки обязательно нужно закрывать, это также важно, как удалять память
	//Сколько раз был вызван метод open(), столько же раз нужно вызвать метод close();
	system("notepad File.txt");
}
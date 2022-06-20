#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	const int SIZE = 256;
	char sz_filename[SIZE] = {}; //sz_ - String Zero
	cout << "Введите имя файла: ";
	cin.getline(sz_filename, SIZE);
	if (strcmp(sz_filename + strlen(sz_filename) - 4, ".txt"))
		strcat(sz_filename, ".txt");
	std::ofstream fout;		//1) Создаем поток
	fout.open(sz_filename, std::ios_base::app);	//2) Открываем поток
	char sz_contents[SIZE] = {};
	cout << "Введите содержимое файла: ";
	cin.getline(sz_contents, SIZE);
	fout << sz_contents; //3) Выводим поток
	fout.close();			//4) Закрываем поток
	//Потоки обязательно нужно закрывать, это также важно, как удалять память
	//Сколько раз был вызван метод open(), столько же раз нужно вызвать метод close();
	char sz_command[SIZE] = "notepad ";
	strcat(sz_command, sz_filename);
	system(sz_command);



	//	std::ofstream fout;		//1) Создаем поток
	//	char name;
	//	cout << "Введите имя файла"; cin >> name >> ".txt";
	//	fout.open(name, std::ios_base::app);	//2) Открываем поток
	//	fout << "Hello World!\n"; //3) Выводим поток
	//	fout.close();			//4) Закрываем поток
	//	//system("notepad File.txt");
	//
	////const int size = 256;
	////	char name[size] = {};
	////	cout << "Введите имя файла"; cin >> name >> ".txt";
	////	std::ofstream fout;
	////	fout.open(name, std::ios_base::app);
	////	fout << "Hello World!\n";
	////	fout.close();
	////	system("notepad File.txt");  
#endif // WRITE_TO_FILE

	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		//TODO read file
		const int n = 256;
		char buffer[n] = {};
		while (!fin.eof()) //eof - end of file
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	system("notepad File.txt");
}
#include<iostream>
#include <fstream>
#include<windows.h>
#include <string>
#include<sstream>
#include<map>

using namespace std;


void Calc() //Задание 1 с калькулятором
{
	int a, b;
	char option;
	cout << "a (+;-;*;/) b...\n> ";
	cin >> a >> option >> b;
	cout << endl;
	switch (option)
	{
	case '+':
		cout << a + b << "\n\n";
		break;
	case '-':
		cout << a - b << "\n\n";
		break;
	case '*':
		cout << a * b << "\n\n";
		break;
	case '/':
		if (b == 0)
		{
			cout << "На ноль делить нельзя!" << "\n\n";
		}
		else
			cout << a / b << "\n\n";
		break;
	default:
		cout << "Неизвестное действие" << "\n\n";
	}
}

char menu()
{
	char arr[50];
	char option;
	int cnt = 0;

	cout << "0. Выйти из программы" << endl;
	cout << "1. Преобразование строки в верхний регистр" << endl;
	cout << "2. Преобразование строки в нижний регистр" << endl;
	cout << "3. Конкатенация строк а и б" << endl;
	cout << "4. Ввод строки в файл" << endl;
	cout << endl;

	cin >> arr;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] >= 0 && arr[i] != '\0')
			cnt++;
	}

	bool flag = ((cnt == 1) && ((arr[0] == '0') || (arr[0] == '1') || (arr[0] == '2') || (arr[0] == '3') || (arr[0] == '4'))) ? 1 : 0;

	cout << endl;

	if (flag)
	{
		option = arr[0];
		return option;
	}
	else
	{
		return 'k';
	}
}

void InputString(string& pa, string& pb)
{
	cin.ignore();
	cout << "Введите строку а: ";
	getline(cin, pa);
	cout << endl << "Введите строку б: ";
	getline(cin, pb);
	cout << endl;
}
void WorkWithString()			//задание 2 со строками
{
	char option;
	cout << "Работа со строками" << "\n\n";

	string a, b, msg;
	string str = "";

	InputString(a, b);

	fstream file;
	ifstream fin;

	string path;

	do {
		option = menu();
		if (option == 'k')
		{
			while (option == 'k')
			{
				cout << "ошибка, попробуйте снова" << endl << endl;
				option = menu();
			}
		}
		switch (option)
		{
		case '0':
			cout << "Досвидания!" << endl;
			break;												//метод выхода
		case '1':
			int answer;
			cout << "Преобразовать строку\n1. a\n2. b" << "\n\n" << "> ";
			cin >> answer;
			cout << endl;
			if (answer == 1)
			{
				for (int i = 0; i < a.length(); i++)
				{
					a[i] = toupper(a[i]);
				}
				cout << "Строка а преобразована в верхний регистр: " << a << "\n\n";			////Преобразование в верхний регистр строки а
			}
			else if (answer == 2)
			{
				for (int i = 0; i < b.length(); i++)
				{
					b[i] = toupper(b[i]);
				}
				cout << "Строка b преобразована в верхний регистр: " << b << "\n\n";		//Преобразование в верхний регистр строки б
			}
			else
				cout << "ошибка" << endl << endl;
			break;
		case '2':
			int answer2;
			cout << endl;
			cout << "Преобразовать строку\n1. a\n2. b" << "\n\n" << "> ";
			cin >> answer2;
			cout << endl;
			if (answer2 == 1)
			{
				for (int i = 0; i < a.length(); i++)
				{
					a[i] = tolower(a[i]);
				}
				cout << "Строка а преобразована в нижний регистр: " << a << "\n\n";	//Преобразование в ниний регистр строки а
			}
			else if (answer2 == 2)
			{
				for (int i = 0; i < b.length(); i++)
				{																//Преобразование в нижний регистр строки б
					b[i] = tolower(b[i]);
				}
				cout << "Строка b преобразована в нижний регистр: " << b << endl;
			}
			else
				cout << "ошибка" << endl;
			break;
		case '3':
			setlocale(LC_ALL, "ru");
			cout << "Конкатенация строк выполнена: " << a + b << "\n\n"; //Конкатенация строк
			break;
		case '4':					//Ввод текста в файл
			int answer3;
			cout << "Создайте файл" << "\n\n";
			cin >> path;
			file.open(path + ".txt", fstream::in | fstream::out | fstream::app);
			cout << "\n" << "Файл успешно создан" << "\n\n";
			cout << "Какую строку записать в файл?\n1. a\n2. b\n3. Обе\n4. Ввести своё сообщение\n> ";
			cin >> answer3;

			if (answer3 == 1)
				file << a;
			else if (answer3 == 2)
				file << b;
			else if (answer3 == 3)
				file << a << ' ' << b;
			else if (answer3 == 4)
			{
				cout << "Введите сообщение: ";
				cin.ignore();
				getline(cin, msg);
				file << msg;
				cout << "\n";
				cout << "Сообщение успешно записано!" << "\n\n";
			}
			else
				cout << "Ошибка" << endl;
			break;
		default:
		{
			cout << "Ошибка" << "\n\n";
		}
		}
	} while (option != '0');
}
void ReadFromFile()				//задание 2 со строками
{
	ifstream fin;
	string path;
	cout << "Введите название файла\n> ";
	getline(cin, path);
	cout << endl;
	fin.open(path + ".txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << "\n\n";
	}
	else
	{
		cout << "Файл открыт!" << "\n\n";
		string str = "";
		while (!fin.eof())
		{
			getline(fin, str);
			cout << str << endl;
		}
	}

}

void SearchWord()
{
	system("chcp 1251");
	string text;
	getline(cin, text);
	istringstream stream(text);
	map<string, int> map;
	for (string word; stream >> word; ++map[word]);
	pair<string, int> pair;
	for (auto element : map) {
		if (pair.second < element.second) pair = element;
	}
	cout << "Наиболее встречаемое слово (" << pair.first << ") встретилось " << pair.second << " раз(а)" << endl;

}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
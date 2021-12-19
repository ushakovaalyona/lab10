#include<iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void message (string msg) {
	SYSTEMTIME t;
	GetLocalTime(&t);
	ofstream fout("log.txt", ofstream::app); // открываем файл 
	fout << t.wDay << "." << t.wMonth << "." << t.wYear << "   " << t.wHour << ":" << t.wMinute << ":" << t.wSecond << "   " << "MESSAGE" << "   " << msg << endl; // запись строки в файл
	fout.close(); // закрываем файл	
};

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string msg;
	int N;
	cout << "Введите количество бочонков в мешочке ";
	cin >> N;
	msg = "Введено количество бочонков в мешке";
	message(msg);
	cout << "Чтобы узнать номер вытягиваемого бочонка, каждый раз нажимайте на любую клавишу. Удачной игры! "<<endl;
	//size_t N;
	vector<int> victor(N);//конструирование вектора длиной N
	for (size_t i = 0; i < N; ++i) {
		victor[i] = i + 1;
	}
	for (int i = 0; i < N; ++i) {
		swap(victor[i], victor[std::rand() % N]);
	}
	for (size_t i = 0; i < N; ++i) {
		cout<<victor[i] <<endl;
		system("pause");
		msg = "Показан номер вытянутого бочонка";
		message(msg);
	}
	}

		

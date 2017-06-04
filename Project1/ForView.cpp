#include <iostream>
#include  <fstream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>	 //console
#include "My_Lib.h"

 //////////////////////////good


void FullClearRow(int y) {														//clear row ->y
	
	SetConsoleCursorPosition(2, y);
	for (int i = 0; i<98; i++)
		cout << " ";
}









////////////////////////////////////uncnoun func
void ClearRow()
{
	SetConsoleCursorPosition(2, 42);
	for (int i = 0; i<90; i++)
		cout << " ";
	SetConsoleCursorPosition(2, 42);
}		

void TabClearRow() {
SetConsoleCursorPosition(0, 5);
	for (int y = 5; y < 40; y++) {
		for (int x = 1; x < 99; x++) {
			
			if (x == 50) {
				SetConsoleCursorPosition(x, y);
				cout << char(179);
			}
			else {
				SetConsoleCursorPosition(x, y);
				cout << " ";
			}
		}
	}
}
//////////////////////////////////Delete
void FullView(int tab) {

	const char * file = "Book.dat";
	const char * file1 = "User.dat";
	Book book;
	User user;
	if (tab == 0) {
		//ifstream fin;
		//fin.open(file, ios_base::in | ios_base::binary);		// binary file
		//														//NOTE: some systems don't accept the ios_base::binary mode
		//if (fin.is_open()) {
		//	SetConsoleCursorPosition(2, 60);
		//	cout << "Here are the current contents of the book"
		//		<< file << " file:\n";
		//	SetConsoleCursorPosition(0, 5);

		//	while (fin.read((char *)&book, sizeof book)) {

				//cout << setiosflags(ios::left);					//viravnivanie
	
			SetConsoleCursorPosition(2, 30);
				cout << char(186) << setw(25) << book.B_name;
				cout << '|' << setw(25) << book.Aut;
				cout << '|' << setw(10) << book.R_date;
				cout << '|' << setw(6) << book.ID_b;
				//cout << '|' << setw(10) << book.Con;
				//cout << '|' << setw(4) << book.Cou;

				printf("|%04d", book.Cou);	  //formatt 0000

				//cout << '|' << setw(2) << book.Rat;
				cout << '|' << setw(6) << book.ID_b;
				//cout << '|' << setw(8) << book.ID_U << endl;


			}
		//	fin.close();
		//}
	//}
	//else {
		//ifstream fin;
		//fin.open(file1, ios_base::in | ios_base::binary);  // binary file
		//												   //NOTE: some systems don't accept the ios_base::binary mode
		//if (fin.is_open()) {
		//	SetConsoleCursorPosition(2, 59);
		//	cout << "Here are the current contents of the user "
		//		<< file << " file1:\n";
		//	int i = 5;
		//	SetConsoleCursorPosition(51, 5);
		//	while (fin.read((char *)&user, sizeof user)) {

		//		SetConsoleCursorPosition(51, i);
		//		cout << setiosflags(ios::left);
		//		cout << setw(15) << user.U_Name << '|' << setw(10) << user.Hbir << endl;
		//		//cout << '|' << setw(11) << user.DateIs;
		//		//cout << '|' << setw(11) << user.Pas << endl;
		//		i++;
		//	}
		//	fin.close();
		//}
	//}


}

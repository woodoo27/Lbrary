#include <iostream>
#include  <fstream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <conio.h>	 //console
#include "My_Lib.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

 /////////////////////////////   Interface
void eatline() { while (cin.get() != '\n') continue; };

void UGI(int tab) {
	SetConsoleTitle("Library V.0.01");
	SetConsoleWinSizePosition(100, 200, 0, 0);
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |/* BACKGROUND_INTENSITY |*/
		FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j <= 100; j++) {
			cout << " ";
		}
	}
	//Table line	
	SetConsoleCursorPosition(0, 0);
	cout << char(201);	 //up
	for (int i = 1; i<100; i++)
		cout << char(205);
	cout << char(187);
	SetConsoleCursorPosition(0, 2); //1 line ------------
	for (int i = 1; i <= 100; i++)
		cout << char(196);
	SetConsoleCursorPosition(0, 4); //2 line ------------
	for (int i = 1; i <= 100; i++)
		cout << char(196);
	SetConsoleCursorPosition(0, 40); //3 line ------------
	for (int i = 1; i <= 100; i++)
		cout << char(196);
	
		for (int i = 3; i < 40; i++) {
			SetConsoleCursorPosition(50, i);
			cout << char(179) << "\n";
		
	}

	SetConsoleCursorPosition(50, 2);   //cross left
	cout << char(194) << "\n";
	SetConsoleCursorPosition(50, 4);  //   cross centr
	cout << char(197) << "\n";
	SetConsoleCursorPosition(50, 40);   	//   cross right
	cout << char(193) << "\n";


	for (int i = 1; i < 43; i++) {	 //left and rihgt
		SetConsoleCursorPosition(0, i);
		cout << char(186);
		SetConsoleCursorPosition(100, i);
		cout << char(186);
	}
	cout << char(200);	 //down
	for (int i = 1; i<100; i++)
		cout << char(205);
	cout << char(188);
	if (0 == tab)
		showmenuBook();
	else
		showmenuUser();
	SetConsoleCursorPosition(5, 1);
	cout << "LIBRARY : ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
	SetConsoleCursorPosition(1, 3);
	cout << "Book : 1";
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |/* BACKGROUND_INTENSITY |*/
		FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
	SetConsoleCursorPosition(51, 3);
	cout << "Member: 2";
	showmenu();
	SetConsoleCursorPosition(30, 45);
	cout << "OPTIONAL";


}

void showmenu() {
	SetConsoleCursorPosition(0, 45);
	cout << "MAIN MENU\n";
	SetConsoleCursorPosition(0, 46);
	cout << "Tab - Panel selection\n";
	SetConsoleCursorPosition(0, 47);
	cout << "Up Down - Navigation\n";
	SetConsoleCursorPosition(0, 48);
	cout << "Esc - Enter\n";
	SetConsoleCursorPosition(0, 49);
	cout << "E - Edit\n";

}

void showmenuBook() {
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |/* BACKGROUND_INTENSITY |*/
		FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
	SetConsoleCursorPosition(30, 46);
	cout << "1 - Edit Book name\t\t\t\t";
	SetConsoleCursorPosition(30, 47);
	cout << "2 - Edit Author Name\t\t\t\t";
	SetConsoleCursorPosition(30, 48);
	cout << "3 - Edit Release date format dd.mm.yyyy\t\t";
	SetConsoleCursorPosition(30, 49);
	cout << "4 - Edit Count Book\t\t\t\t";
	SetConsoleCursorPosition(30, 50);
	cout << "5 - Edit Context\t\t\t\t";
	SetConsoleCursorPosition(30, 51);
	cout << "6 - Edit Rate\t\t\t\t";
	SetConsoleCursorPosition(30, 52);
	cout << "7 - Edit ID Book\t\t\t\t";
}

void showmenuUser() {
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |/* BACKGROUND_INTENSITY |*/
		FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
	SetConsoleCursorPosition(30, 46);
	cout << "1 - Edit User name\t\t\t\t";
	SetConsoleCursorPosition(30, 47);
	cout << "2 - Edit Surname\t\t\t\t";
	SetConsoleCursorPosition(30, 48);
	cout << "3 - Edit Patronymic\t\t\t\t";
	SetConsoleCursorPosition(30, 49);
	cout << "4 - Edit Birthday user  format dd.mm.yyyy";
	SetConsoleCursorPosition(30, 50);
	cout << "5 - Edit ID_user\t\t\t\t";
	SetConsoleCursorPosition(30, 51);
	cout << "6 - Edit List book ID\t\t\t\t";
	SetConsoleCursorPosition(30, 52);
	cout << "7 - Number of books on hand\t\t\t\t";
}

/////////////////////////////Good
int ButtonTab(int t)
{
	t++;
	if (2 == t)
	{
		t = 0;
	}
	if (0 < t) {
		SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |/* BACKGROUND_INTENSITY |*/
			FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
		SetConsoleCursorPosition(1, 3);
		std::cout << "Book : 1"; //inser id book
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY |
			FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
		SetConsoleCursorPosition(51, 3);
		std::cout << "Member: 2";  //insert id user
	}
	else
	{
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY |
			FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
		SetConsoleCursorPosition(1, 3);
		std::cout << "Book : 1";   //inser id book
		SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |/* BACKGROUND_INTENSITY |*/
			FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
		SetConsoleCursorPosition(51, 3);
		std::cout << "Member: 2"; //insert id user
	}
	return t;
}

bool ButtonQuit() {
	cout << "q - key to quit" << endl;
	char key = _getch();
	if (key == 'q' || key == 'Q')
		return false;
	return true;
}

int ButtonReturn(int j) {
	j++;
	if (10 == j) {
		cout << "do not play\n";
		j = 0;
	}
	return j;
}

///////////////////////////////////////////

//////////////////////console

void SetConsoleWinSizePosition(int width = 0, int heigth = 0, short x_position = 0, short y_position = 0) {
	HWND hWnd = GetForegroundWindow();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, x_position, y_position, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = heigth;
	windowSize.Left = 0;
	windowSize.Right = 100;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { 100 + 1 , heigth + 1 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void SetConsoleCursorPosition(short x_position, short y_position) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _coordPosition = { x_position , y_position };
	SetConsoleCursorPosition(hConsole, _coordPosition);
}

void ReadMyFile(int tab, string filename) {
	//const char * file = "Book.dat";
	//const char * file1 = "User.dat";

	string file = filename;
	
	Book book;
	User user;
	if (tab == 0) {
		ifstream fin;
		fin.open(file, ios_base::in | ios_base::binary);		// binary file
																//NOTE: some systems don't accept the ios_base::binary mode
		if (fin.is_open()) {
			SetConsoleCursorPosition(2, 60);
			cout << "Here are the current contents of the book"
				<< file << " file:\n";
			SetConsoleCursorPosition(0, 5);

			while (fin.read((char *)&book, sizeof book)) {

				cout << setiosflags(ios::left);					//viravnivanie
				cout << char(186) << setw(20) << book.B_name;
				cout << '|' << setw(5) << book.ID_b;
				cout << '|' << setw(3) << book.Cou << endl;
			}
			fin.close();
		}
	}
	else {
		ifstream fin;
		fin.open(file, ios_base::in | ios_base::binary);  // binary file
														   //NOTE: some systems don't accept the ios_base::binary mode
		if (fin.is_open()) {
			SetConsoleCursorPosition(2, 59);
			cout << "Here are the current contents of the user "
				<< file << " file1:\n";
			int i = 5;
			SetConsoleCursorPosition(51, 5);
			while (fin.read((char *)&user, sizeof user)) {

				SetConsoleCursorPosition(51, i);
				cout << setiosflags(ios::left);
				cout << setw(15) << user.U_Name << '|' << setw(10) << user.Hbir << endl;
				//cout << '|' << setw(11) << user.DateIs;
				//cout << '|' << setw(11) << user.Pas << endl;
				i++;
			}
			fin.close();
		}
	}
}

void Add(int tab,string filename) {																	//add user or book
	//const char * file = "Book.dat";
	//const char * file1 = "User.dat";
	string file = filename;
	Book book;
	User user;
	char buf[16];
	int temp;

	if (tab == 0) {
		ofstream fout(file,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout.is_open())
		{
			
			SetConsoleCursorPosition(2, 41); 
			ClearRow();
			cerr << "Can't open " << file << " file for output:\t\t\t\t\t\n";
			exit(EXIT_FAILURE);
		}

		SetConsoleCursorPosition(2, 41);
		cout << "Enter book name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.B_name, 30);
		if (book.B_name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			return;	
		}
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Author Name ->Format Name Surname Patronymic:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.Aut, 100);
		if (book.Aut[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Release date ->Format dd.mm.yyyy:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.R_date, 11);
		if (book.R_date[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book context:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.Con, 30);
		if (book.Con[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream


		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book count:\t\t\t\t\t\n";
		ClearRow();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1>temp || temp>11)
		{

			SetConsoleCursorPosition(2, 41);
			cout << "Erorr! Enter an integer between 1 and 10, inclusive:\t\t\t\n";
			ClearRow();
			cin.getline(buf, 5);
			temp = atoi(buf);
			
		}
		book.Cou = temp;

		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book rate:\t\t\t\t\t\n";
		ClearRow();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (0>temp || temp>11)
		{

			SetConsoleCursorPosition(2, 41);
			cout << "Erorr! Enter an integer between 0 and 5, inclusive.\t\t\t\n";
			ClearRow();
			cin.getline(buf,5);
			temp = atoi(buf);

		}
		book.Rat = temp;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book ID:\t\t\t\t\t\n";
		ClearRow();
		cin >> book.ID_b;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		if (book.B_name[0] != '\0')
			fout.write((char *)&book, sizeof book);
		fout.close();
	}
	
	else {
		ofstream fout(file,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout.is_open())
		{
			
			SetConsoleCursorPosition(2, 41);
			ClearRow();
			cerr << "Can't open " << file << " file for output:\t\t\t\t\t\n";
			exit(EXIT_FAILURE);
		}

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Member name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(user.U_Name, 30);
		if (user.U_Name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			return;
		}

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter birthday user  format (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.Hbir, 11);
		if (user.Hbir[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Date of issue  format dd.mm.yyyy (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.DateIs, 11);
		if (user.DateIs[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		SetConsoleCursorPosition(2, 41);
		cout << "Enter ID-user format 0000 (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.ID_vs_ID, 5);
		if (user.ID_vs_ID[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		if (user.U_Name[0] != '\0')
			fout.write((char *)&user, sizeof user);
		fout.close();
	}
	
	SetConsoleCursorPosition(2, 41);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
	ClearRow();
	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());
}




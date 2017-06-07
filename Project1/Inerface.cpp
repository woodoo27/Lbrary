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
int ButtonTab(int t)				   //Tab
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

bool ButtonQuit() {				                              //Quit
	cout << "q - key to quit" << endl;
	char key = _getch();
	if (key == 'q' || key == 'Q')
		return false;
	return true;
}		  //

int ButtonReturn(int j) {									 //joke
	j++;
	if (10 == j) {
		cout << "do not play\n";
		j = 0;
	}
	return j;
}

int ButtonFullMode(int t) {
	t++;
	if (2 == t)
	{
		t = 0;
	}
	return t;
}
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







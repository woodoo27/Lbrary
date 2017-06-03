/*#include <iostream>     // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib>      // for exit()
#include <Windows.h>
#include  <iostream>      // для  большинства  систем  не  требуется
#include  <fstream>
#include  <iomanip>
#include  <string>
#include  <cstdlib>
#include <cstdio>
#include <ios>
#include  <string> 	  //  (или  stdlib.h)  для  exit()

using namespace std;

struct planet
{
char name[LIM];     // name of planet
double population;  // its population
double g;           // its acceleration of gravity
};


//Struct_end/////////////////////////////////////////////////////////////

const char * file = "test.dat";  // ASSUMED TO EXIST (binary.cpp example)
inline void eatline() { while (std::cin.get() != '\n') continue; }

int main()
{

struct planet pl;
struct Book bk;
struct User us;
cout << fixed;
// show initial contents
fstream finout;     // read and write streams


finout.open(file,
ios::in | ios::out | ios::app | ios::binary); 	//NOTE: Some Unix systems require omitting | ios::binary
int ct = 0;
if (finout.is_open())
{
finout.seekg(0);    // go to beginning
cout << "Here are the current contents of the "
<< file << " file:\n";
while (finout.read((char *)&pl, sizeof pl))
{
cout << ct++ << ": " << setw(LIM) << pl.name << ": "
<< setprecision(0) << setw(12) << pl.population
<< setprecision(2) << setw(6) << pl.g << endl;
}
if (finout.eof())
finout.clear(); // clear eof flag
else
{
cerr << "Error in reading " << file << ".\n";
//exit(EXIT_FAILURE);
}
}
else
{
cerr << file << " could not be opened -- bye.\n";
//exit(EXIT_FAILURE);
}
//// change a record




cout << "Enter the record number you wish to change: ";
int rec;
cin >> rec;
eatline();              // get rid of newline


//						//for edit line
//						////////////////////////////////////////////////////////////////////////////////////////////
if (0 <= rec && rec <= ct)
{
streampos place = rec * sizeof pl;  // convert to streampos type
finout.seekg(place);    // random access
if (finout.fail())
{
cerr << "Error on attempted seek\n";
//exit(EXIT_FAILURE);
}
finout.read((char *)&pl, sizeof pl);
cout << "Your selection:\n";
cout << rec << ": " << setw(LIM) << pl.name << ": "
<< setprecision(0) << setw(12) << pl.population
<< setprecision(2) << setw(6) << pl.g << endl;
if (finout.eof())
finout.clear();     // clear eof flag
cout << "Enter planet name: ";
cin.get(pl.name, LIM);
eatline();
cout << "Enter planetary population: ";
cin >> pl.population;
cout << "Enter planet's acceleration of gravit: ";
cin >> pl.g;
finout.seekp(place);    // go back
finout.write((char *)&pl, sizeof pl) << flush;
if (finout.fail())
{
cerr << "Error on attempted write\n";
//exit(EXIT_FAILURE);
}
//show revised file
}

else
{
cerr << "Invalid record number -- bye\n";
//exit(EXIT_FAILURE);

}


////////////////////////////////////////////////////////////////////////////////////////////////



ct = 0;
finout.seekg(0);            // go to beginning
cout << "Here are the new contents of the " << file
<< " file:\n";
while (finout.read((char *)&pl, sizeof pl))
{
cout << ct++ << ": " << setw(LIM) << pl.name << ": "
<< setprecision(0) << setw(12) << pl.population
<< setprecision(2) << setw(6) << pl.g << endl;
}
finout.close();
cout << "Done.\n";
system("pause");
}																				 */
/////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>	 //console
#include <Windows.h>
#include  <iostream>      // для  большинства  систем  не  требуется
#include  <fstream>
#include <iomanip>
#include "Header.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
inline void eatline() { while (std::cin.get() != '\n') continue; }

using namespace std;
const int LIM = 20;		 //for file


//Struct/////////////////////////////////////////////////////////////
struct Book {					//  структура данных записной книжки
	char B_name[100];			//1.  Book name
	char Aut[100];				//2.  Author	Name
	char R_date[11];			//3.  Release date   format dd.mm.yyyy
	char Con[30];				//4.  Context
	int Cou;					//5.  Count Book
	int Rat;					//6.	rate
	int ID_b;					//7.	ID Book
	int ID_U;					//8.	ID User??????
};
struct User {					//  структура данных пользователя
	char U_Name[100];			//1.  Format User name Surname Patronymic
	char Hbir[11];				//2.  Happy birthday user  format dd.mm.yyyy
	char DateIs[11];			//3.  Date of issue  format dd.mm.yyyy
	char ID_vs_ID[40];			//5.  0-int ID-user 	  1-5 -book ID owner  6 -Number of books on hand
	int Pas;					//Passport
};



int main(){
	//setlocale(LC_ALL, "RUS");
	int  tab = 0;
	bool quit = true;
	int joke = 0;
	UGI(tab);
	showmenuBook();
	ReadMyFile(0);
	ReadMyFile(1);
	for (; quit == true;) {
				
			if (_kbhit()) {
				switch (_getch()) {
				case 9: {
					SetConsoleCursorPosition(0, 45);
					tab = ButtonTab(tab);

					if (0 == tab)
						showmenuBook();
					else
						showmenuUser();

					break;
				}
				case 16: cout << "SHIFT=10";
					break;
				case '1': {
					showmenuBook();
					cout << "ONE=31";
					break;
				}
				case 27: cout << "Esc=27 ";
					break;
				case 72: cout << "MVK_UP = 72";
					break;
				case 75: cout << "MVK_LEFT = 75";
					break;
				case 77: cout << "MVK_RIGHT = 77";
					break;
				case 80: cout << "MVK_DOWN = 80";
					break;
				case 'e':;
				case 'E': {
					if (0 == tab) {
						showmenuBook();
						Add(tab);
					}
					else {
						showmenuUser();
						Add(tab);
					}
					break;

				}
				case 'q':;
				case 'Q': {
					quit = ButtonQuit();
					break;
				}
				case 13: {
					joke = ButtonReturn(joke);
					break;
				}
				default:
					cout << " That's not a choice.";
				}
				SetConsoleCursorPosition(45, 5);
				ReadMyFile(1);		  // курсу на парковкy
				ReadMyFile(0);
				SetConsoleCursorPosition(2, 42);
				//SetConsoleCursorPosition(0, 65);
				//cout << "test pool tab =" << tab;
				
			}	
		}
	
	cout << " Bye!";
	return 0;
}

void showmenu(){
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
void showmenuBook(){
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
void showmenuUser(){
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
void report(){
	cout << " It's been an excellent week for business . \n "
		" Salesareup 120 % . Expensesare down 35 % . \n ";
}

void comfort(){
	cout << " Your emp loyees think you are the finest CEO \n "
		" in the industry . The board of directors think \n "
		" you are the finest СЕО in the industr  . \n ";
}

/////////////////////////////Good
int ButtonTab(int t)
{
	t++;
	if (2 == t)
	{
		t = 0;
	}
	if (0 < t){
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
///////////////////////////////////////////

bool ButtonQuit(){
	cout << "q - key to quit" << endl;
	char key = _getch();
	if (key == 'q' || key == 'Q')
		return false;
	return true;
}
int ButtonReturn(int j){
	j++;
	if (10 == j){
		cout << "do not play\n";
		j = 0;
	}
	return j;
}

void SetConsoleWinSizePosition(int width = 0, int heigth = 0, short x_position = 0, short y_position = 0){
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



void SetConsoleCursorPosition(short x_position, short y_position){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _coordPosition = { x_position , y_position };
	SetConsoleCursorPosition(hConsole, _coordPosition);
}


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
	SetConsoleCursorPosition(50,40);   	//   cross right
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
void ReadMyFile(int tab) {
	const char * file = "Book.dat";
	const char * file1 = "User.dat";
	Book book;
	User user;
	if(tab==0){
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
		fin.open(file1, ios_base::in | ios_base::binary);  // binary file
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
				cout << setw(15) << user.U_Name<< '|' << setw(10)<<user.Hbir << endl;
				//cout << '|' << setw(11) << user.DateIs;
				//cout << '|' << setw(11) << user.Pas << endl;
				i++;
			}
			fin.close();
		}
	}
	}


void Add(int tab) {																	//add user or book
	const char * file = "Book.dat";
	const char * file1 = "User.dat";
	Book book;
	User user;

	if (tab == 0) {
		ofstream fout(file,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout.is_open())
		{
			cerr << "Can't open " << file << " file for output:\n";
			exit(EXIT_FAILURE);
		}
		SetConsoleCursorPosition(2, 41);
		cout << "Enter book name (enter a blank line to quit):\t\t\t\t\n";
		ClearRow();
		cin.get(book.B_name, 30);
		while (book.B_name[0] != '\0')
		{
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY |
				FOREGROUND_RED | FOREGROUND_RED| /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
			SetConsoleCursorPosition(2, 21);
			cout << "xxxxx";



			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Author Name ->Format Name Surname Patronymic:\n ";
			ClearRow();
			cin.get(book.Aut, 100);
			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Release date ->Format dd.mm.yyyy:\t\t\t\t\t\t\n ";
			ClearRow();
			cin.get(book.R_date, 11);
			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Book context:\t\t\t\t\t\t\t\t\t\t\t\n ";
			ClearRow();
			cin.get(book.R_date, 30);
			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Book count:\t\t\t\t\t\t\t\t\t\n ";
			ClearRow();
			cin >> book.Cou;
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Book rate:\t\t\t\t\t\t\t\t\t\t\n ";
			ClearRow();
			cin >> book.Rat;
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Book ID:\t\t\t\t\t\t\t\t\t\t\t\n ";
			ClearRow();
			cin >> book.ID_b;
			eatline();
			fout.write((char *)&book, sizeof book);
			SetConsoleCursorPosition(2, 41);
			cout << "Enter book name (enter a blank line to quit):\t\n";
			ClearRow();
			cin.get(book.B_name, 30);

			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_INTENSITY |
				FOREGROUND_RED | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_INTENSITY);
			SetConsoleCursorPosition(2, 21);
			cout << " ";
		}
		fout.close();
	}
	else {
		ofstream fout(file1,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout.is_open())
		{
			cerr << "Can't open " << file << " file for output:\t\t\t\n";
			exit(EXIT_FAILURE);
		}
		SetConsoleCursorPosition(2, 41);
		cout << "Enter Member name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(user.U_Name, 30);
		while (user.U_Name[0] != '\0')
		{
			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Member birthday ->Format dd.mm.yyyy:\t\t\t\t\t\t\n";
			ClearRow();
			cin.get(user.Hbir, 11);
			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Date of issue ->Format dd.mm.yyyy:\t\t\t\t\t\t\n";
			ClearRow();
			cin.get(user.DateIs, 11);
			eatline();
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Member passport:\t\t\t\t\t\t\t\n";
			ClearRow();
			cin >> user.Pas;
			/*cout << "Enter Book ID: ";
			cin >> book.ID_b;*/
			eatline();
			fout.write((char *)&user, sizeof user);
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Member name (enter a blank line to quit):\t\t\t\n";
			ClearRow();
			cin.get(user.U_Name, 30);														   
		}
		fout.close();
	}
}



void ClearRow()
{
	SetConsoleCursorPosition(2, 42);
	for(int i=0;i<90;i++)
	cout << " "  ;
	SetConsoleCursorPosition(2, 42);

}
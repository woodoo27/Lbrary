#pragma once
#ifndef _my_lib_h_
#define  _my_h_lib_
//Struct/////////////////////////////////////////////////////////////


using namespace std;
const int LIM = 20;		 //for file
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

void eatline();
/////////////////////////////////////////////////func console

void SetConsoleWinSizePosition(int width, int heigth, short x_position, short y_position);
void SetConsoleCursorPosition(short x_position, short y_position);

/////////////////////////////////////////////////func file
void ReadMyFile(int tab,string filename);
void Add(int tab,string filename);	
string Filename(int tab, string filename);
/////////////////////////////////////////////////func menu & button
void showmenu();
void showmenuBook();
void showmenuUser();
void UGI(int tab);	
int ButtonReturn(int j);
int ButtonTab(int tab);
bool ButtonQuit();




/////for delete
void TabClearRow();
void ClearRow();
void FullView(int tab);	




 ////////////////////Final
void OpenFile(string filenamen, int tab);				 





void FullClearRow(int y);










void SaveFile();
void SaveFile1();

#endif
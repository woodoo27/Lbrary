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
void Filename(int tab, string filename);		  

void RandomLineEdit(int tab, string filename);

void EditID(int tab, string filename);	  //temp

void Del(int tab, string filename);

/////////////////////////////////////////////////func menu & button
void showmenu();
void showmenuBook();
void showmenuUser();
void UGI(int tab);	
int ButtonReturn(int j);
int ButtonTab(int tab);
bool ButtonQuit();
int ButtonFullMode(int t);

//////////////////////////////////////////////for clear
void FullClearRow(int y);
void FullClearRowPanel(int y,int fulllmode);
void ClearRow();
void BookClearRow();



  ////////////////////////////////////////Masage
void MassageBook_1();
void MassageBook_2();
void MassageBook_3();
void MassageBook_4();
void MassageBook_5();
void MassageBook_6();
void MassageBook_7();
void MassageBook_7();
void MassageBook_8();
void MassageBook_9();
void MassageBook_10();
void MassageBook_11();
void MassageBook_12();
void MassageBook_13();

void MassageMem_1();
void MassageMem_2();
void MassageMem_3();
void MassageMem_4();
void MassageMem_5();
void MassageMem_6();
void MassageMem_7();
void MassageMem_8();
void MassageMem_9();

void MassageFile_1();
void MassageFile_2();
void MassageFile_3();
void MassageFile_4();
void MassageFile_5();








void ReadMyFule(int tab, string filename);

#endif

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>	 //console
#include <Windows.h>
#include <string>
#include "My_Lib.h"


int main(){
	//setlocale(LC_ALL, "RUS");
	int  tab = 0;
	bool quit = true;
	int fullmode = 0;
	int joke = 0;
	string st_book;
	string st_user;
	bool chek_edit;
	int str_cou_u = 0;   //count string	user
	int str_cou_b = 0;   //count string	book
	
	UGI(tab);
	showmenuBook();
	SetConsoleCursorPosition(2, 42);
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

					ClearRow();
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

					ClearRow();
					break;
				case 72: cout << "MVK_UP = 72";

					ClearRow();
					break;
				case 75: cout << "MVK_LEFT = 75";

					ClearRow();
					break;
				case 77: cout << "MVK_RIGHT = 77";

					ClearRow();
					break;
				case 80: cout << "MVK_DOWN = 80";

					ClearRow();
					break;
				case 'e':;								   //work
				case 'E': {
					
						if (0 == tab) {
							showmenuBook();
							cin.clear(0);
							cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
							Add(tab, st_book);
							ReadMyFile(tab, st_book);
						}
						else {
							showmenuUser();
							cin.clear(0);
							cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
							Add(tab, st_user);
							ReadMyFile(tab, st_user);
						}
					
					
					ClearRow();
					break;
				}						   
				case 's':;
				case 'S': {	
					if (tab == 0) {
						Del(tab, st_book);
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());
						CopyFile_my(tab, st_book);
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());
						ReadMyFile(tab, st_book);
					}
					else {
						Del(tab, st_user);
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());
						CopyFile_my(tab, st_user);
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());
						ReadMyFile(tab, st_user);
					}
				} 
						  cin.clear(0);
						  cin.ignore(cin.rdbuf()->in_avail());
					ClearRow();
					break;
				case 'q':;								  //work
				case 'Q': {
					quit = ButtonQuit();
					ClearRow();
					break;
				}
				case 't':;
				case 'T': {
					fullmode = ButtonFullMode(fullmode);
					ClearRow();	
					if (fullmode == 1) {
						for (int i = 5; i < 40; i++)
						FullClearRowPanel(i, fullmode);	  
						FullClearRow(41);

						if (tab == 0)
							ReadMyFule(tab, st_book);
						else
							ReadMyFule(tab, st_user);
					}
					else {
						for (int i = 5; i < 40; i++)
							FullClearRowPanel(i,fullmode);
						if(tab==0)
							ReadMyFile(tab, st_book);
						else
							ReadMyFile(tab, st_user);
					}

					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
					break;
				}
				case 'o':;
				case 'O': {
					if (tab == 0) {
						FullClearRow(41);
						BookClearRow();
						SetConsoleCursorPosition(2, 41);
						cout << "Enter file name ->";
						std::cin >> st_book;
						ReadMyFile(tab, st_book);
					}
					else {
						FullClearRow(41);
						SetConsoleCursorPosition(2, 41);
						cout << "Enter file name ->";
						std::cin >> st_user;
						ReadMyFile(tab, st_user);
					}
					fullmode++;
					ClearRow();
					break; 
				}case 'r':;
				case 'R': {	  
					if (tab == 0) {
						RandomLineEdit(tab, st_book);
						ReadMyFile(tab, st_book);
					}
					else {
						RandomLineEdit(tab, st_user);
						ReadMyFile(tab, st_user);
					}

					ClearRow();
					break;
				}
				case 'f':;
				case 'F': {									   //chek file not new

					if (tab == 0) {


						FullClearRow(41);
						SetConsoleCursorPosition(2, 41);
						cout << "Enter new file name for Book DataBase->";
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
						cin >> st_book;
						Filename(tab, st_book);
					}
					else {
						FullClearRow(41);
						SetConsoleCursorPosition(2, 41);
						cout << "Enter new file name for User DataBase->";	 
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
						cin >> st_user;
						Filename(tab, st_user);
					}
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());
					ClearRow();
					break;	   
				}
				case 13: {
					joke = ButtonReturn(joke);
					break;
				}
				default:
					cout << " That's not a choice.";
				}
				//SetConsoleCursorPosition(45, 5);
				//ReadMyFile(1);		  // курсу на парковкy
				//ReadMyFile(0);
				//SetConsoleCursorPosition(2, 42);
				ClearRow();
				
			}	
		}
	
	cout << " Bye!";
	return 0;
}


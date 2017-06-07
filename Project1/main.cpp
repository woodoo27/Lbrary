
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
				case 'e':;
				case 'E': {
					if (0 == tab) {
						showmenuBook();
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
						Add(tab,st_book);
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
				//case 's':;
				//case 'S': {
				//	break;
				//}
				case 'q':;								  //work
				case 'Q': {
					quit = ButtonQuit();
					ClearRow();
					break;
				}
				case 't':;
				case 'T': {
					ClearRow();
					for(int i=5;i<40;i++)
						FullClearRow(41);
					ReadMyFule (tab, st_book);
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
						cin >> st_book;
						Filename(tab, st_book);
					}
					else {
						FullClearRow(41);
						SetConsoleCursorPosition(2, 41);
						cout << "Enter new file name for User DataBase->";	 
						Filename(tab, st_user);
					}

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


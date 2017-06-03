
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>	 //console
#include <Windows.h>
#include "My_Lib.h"


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
						SetConsoleCursorPosition(2, 42);
						ClearRow();
					}
					else { 
						showmenuUser();
						Add(tab);

						SetConsoleCursorPosition(2, 42);
						ClearRow();
					}
					break;
				}
				case 's':;
				case 'S': {
					void TabClearRow();

					ReadMyFile(0);
					ReadMyFile(1); 

					SetConsoleCursorPosition(2, 42);
					ClearRow();	 
					break;
				}
				case 'q':;
				case 'Q': {
					quit = ButtonQuit();
					break;
				}
				case 'f':;
				case 'F': {
					FullClearRow();
					FullView(tab);
					ReadMyFile(0);
					ReadMyFile(1);

					SetConsoleCursorPosition(2, 42);
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
				SetConsoleCursorPosition(45, 5);
				//ReadMyFile(1);		  // курсу на парковкy
				//ReadMyFile(0);
				SetConsoleCursorPosition(2, 42);
				
			}	
		}
	
	cout << " Bye!";
	return 0;
}


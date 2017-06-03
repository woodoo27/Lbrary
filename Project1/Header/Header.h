#pragma once
/////////////////////////////////////////////////func console

void SetConsoleWinSizePosition(int width, int heigth, short x_position, short y_position);
void SetConsoleCursorPosition(short x_position, short y_position);

/////////////////////////////////////////////////func file
void ReadMyFile(int tab);
void Add(int tab);

/////////////////////////////////////////////////func menu & button
void showmenu();
void showmenuBook();
void showmenuUser();
void UGI(int tab);	
int ButtonReturn(int j);
int ButtonTab(int tab);
bool ButtonQuit();
void ClearRow();
/////////////////////////////////////////////////func unsort


void report();		//temp
void comfort();	 


/////////////////////////////////////////////////func struct
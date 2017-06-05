#include <iostream>
#include  <fstream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <conio.h>	 //console
#include "My_Lib.h"



void OpenFile(string filename, int tab){
string file =  filename ;
Book book;
User user;


if (tab = 0) {
	ifstream fin_B;

	fin_B.open(file, ios_base::in | ios_base::binary);		// binary file

	if (fin_B.is_open()) {
				
		FullClearRow(41);
		SetConsoleCursorPosition(15, 3);
		cout << "Name Book's file->"
			<< file << " open:\n";
		SetConsoleCursorPosition(0, 5);
		while (fin_B.read((char *)&book, sizeof book)) {

			cout << setiosflags(ios::left);					//viravnivanie
			cout << char(186) << setw(20) << book.B_name;
			cout << '|' << setw(5) << book.ID_b;
			cout << '|' << setw(3) << book.Cou << endl;
		}
		fin_B.close();

	}
	else {
		FullClearRow(41);
		SetConsoleCursorPosition(60, 3);
		cout << "Error open file->" << file << endl;
	}
	fin_B.close();
}
   else{
	  
		ifstream fin_U;
		fin_U.open(file, ios_base::in | ios_base::binary);		// binary file
		int i = 5;														//NOTE: some systems don't accept the ios_base::binary mode
		if (fin_U.is_open()) {
			FullClearRow(42);
			SetConsoleCursorPosition(1, 42);
			cout << "Name User's file->"
				<< file << " file:\n";

			fin_U.read((char *)&user, sizeof user);
			SetConsoleCursorPosition(51, i);
			cout << setiosflags(ios::left);
			cout << setw(15) << user.U_Name << '|' << setw(10) << user.Hbir << endl;
			//cout << '|' << setw(11) << user.DateIs;
			//cout << '|' << setw(11) << user.Pas << endl;
			i++;
		}
		else {
			FullClearRow(42);
			SetConsoleCursorPosition(2, 42);
			cout << "Error open file->" << file << endl;

		}
		fin_U.close();
	 }
}
///////////////////////////////////////////////////not corect

string Filename(int tab, string filename) {				//not work corect
	ofstream fout(filename.c_str());  // create output stream object for new file and call it fout
	fout.close();           // close file
	return filename;
	
}


void SaveFile() {			   ///not work corect  !!!!!!!!!!!!!!!!!!!
	const char * file = "Book.dat";
	const char * file1 = "User.dat";
	Book book;
	User user;

		ofstream fout_B(file,
			ios_base::out | ios_base::app | ios_base::binary);			//NOTE: some systems don't accept the ios::binary mode
		if (!fout_B.is_open())
		{
			//ClearRow();
			//SetConsoleCursorPosition(2, 41);
			FullClearRow(41);
			SetConsoleCursorPosition(2, 41);
			cerr << "Can't open " << file << " file for output:"<<endl;
			exit(EXIT_FAILURE);
		}

		fout_B.write((char *)&book, sizeof book);

		//ClearRow();
		//SetConsoleCursorPosition(2, 41);
		FullClearRow(41);
		SetConsoleCursorPosition(2, 41);
		cout << "Save->" << file << endl;
		fout_B.close();

		ofstream fout_U(file1,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout_U.is_open())
		{
			//ClearRow();
			//SetConsoleCursorPosition(2, 42);
			FullClearRow(42);
			SetConsoleCursorPosition(2, 42);
			cerr << "Can't open ->" << file1 << " file for output:"<<endl;
			exit(EXIT_FAILURE);
		}


		fout_U.write((char *)&user, sizeof user);

		//ClearRow();
		//SetConsoleCursorPosition(2, 42);
		FullClearRow(42);
		SetConsoleCursorPosition(2, 42);
		cout << "Save->" << file1 << endl;

		fout_U.close();

}
void SaveFile1() {
	const char * file = "Book.dat";
	const char * file1 = "User.dat";
	Book book;
	User user;

	ofstream fout_B(file,
		ios_base::out | ios_base::app | ios_base::binary);			//NOTE: some systems don't accept the ios::binary mode
	if (!fout_B.is_open())
	{
		
		cerr << "Can't open " << file << " file for output:" << endl;
		exit(EXIT_FAILURE);
	}

	fout_B.write((char *)&book, sizeof book);
	fout_B.close();

	ofstream fout_U(file1,
		ios_base::out | ios_base::app | ios_base::binary);
	//NOTE: some systems don't accept the ios::binary mode
	if (!fout_U.is_open())
	{
		FullClearRow(42);
		SetConsoleCursorPosition(2, 42);
		cerr << "Can't open ->" << file1 << " file for output:" << endl;
		exit(EXIT_FAILURE);
	}


	fout_U.write((char *)&user, sizeof user);

	fout_U.close();

}






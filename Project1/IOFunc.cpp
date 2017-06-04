#include <iostream>
#include  <fstream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <conio.h>	 //console
#include "My_Lib.h"



void OpenFile(string filename, int tab){
string file =  filename ;
string file1 = filename ;
Book book;
User user;


if (tab = 0) {
	ifstream fin_B;

	fin_B.open(file, ios_base::in | ios_base::binary);		// binary file

	if (fin_B.is_open()) {
				
		FullClearRow(41);
		SetConsoleCursorPosition(2, 41);
		cout << "Here are the current contents of the book->"
			<< file << " file:\n";
		fin_B.read((char *)&book, sizeof book);

	}
	else {
		FullClearRow(41);
		SetConsoleCursorPosition(2, 41);
		cout << "Error open file->" << file << endl;
	}
	fin_B.close();
}
   else{
	  
		ifstream fin_U;
		fin_U.open(file1, ios_base::in | ios_base::binary);		// binary file
																//NOTE: some systems don't accept the ios_base::binary mode
		if (fin_U.is_open()) {
			FullClearRow(42);
			SetConsoleCursorPosition(2, 42);
			cout << "Here are the current contents of the book->"
				<< file1 << " file:\n";

			fin_U.read((char *)&book, sizeof book);
		}
		else {
			FullClearRow(42);
			SetConsoleCursorPosition(2, 42);
			cout << "Error open file->" << file1 << endl;

		}
		fin_U.close();
	 }
}
///////////////////////////////////////////////////not corect

string Filename(int tab) {				//not work corect
	string filename;
	
	if (tab==0){
		FullClearRow(41);
		SetConsoleCursorPosition(2, 41);
	cout << "Enter name for name for Book DataBase->"; }
	else{
		FullClearRow(41);
		SetConsoleCursorPosition(2, 41);
		cout << "Enter file name for User DataBase->";
	}
	cin >> filename;
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






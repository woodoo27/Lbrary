#include <iostream>
#include  <fstream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <cstdlib> 
#include <conio.h>	 //console
#include "My_Lib.h"



//////////////////////////////////////////////Create new file
string Filename(int tab, string filename) {				
	ofstream fout(filename.c_str());  // create output stream object for new file and call it fout
	fout.close();					  // close file
	return filename;
	
}
//////////////////////////////////////////////Read file
void ReadMyFile(int tab, string filename) {
	//const char * file = "Book.dat";
	//const char * file1 = "User.dat";
	int str = 1;
	string file = filename;
	int x = 0;
	int y = 0;
	Book book;
	User user;
	int nrow = 0;
	
	

	//for (int i = 5; i < 35; i++) {
	//	SetConsoleCursorPosition(1, i);
	//	cout <<  setfill(' ') << setw(45) << " " << endl;	 }


	if (tab == 0) {
		ifstream fin;
		fin.open(file, ios_base::in | ios_base::binary);		// binary file
																//NOTE: some systems don't accept the ios_base::binary mode
		if (fin.is_open()) {
			SetConsoleCursorPosition(10, 3);
			cout << setw(30) << file << " - open";

			y = 5;
			SetConsoleCursorPosition(0, 5);
			while (fin.read((char *)&book, sizeof book)) {
			 	 
				cout << setiosflags(ios::left);					//viravnivanie
				cout << char(186)<<nrow++<<":" << setw(20) << book.B_name;
				cout << '|'  << setw(5) << book.ID_b;
				cout << '|'  << setw(3) << book.Cou << endl;
				str++;
				y++;
			} nrow = 0;
			 fin.close();
			 
			
			
		}
	}
	else {
		ifstream fin;
		fin.open(file, ios_base::in | ios_base::binary);  // binary file
														  //NOTE: some systems don't accept the ios_base::binary mode
		if (fin.is_open()) {
			SetConsoleCursorPosition(62, 3);
			cout << setw(30) << file << " - open";
			int i = 5;

			SetConsoleCursorPosition(51, 5);
			while (fin.read((char *)&user, sizeof user)) {

				SetConsoleCursorPosition(51, i);
				cout << setiosflags(ios::left);
				cout << nrow++ << ":" <<setw(15) << user.U_Name << '|' << setw(10) << user.Hbir << endl;
				//cout << '|' << setw(11) << user.DateIs;
				//cout << '|' << setw(11) << user.Pas << endl;
				i++;
			}  nrow = 0;
			fin.close();
		}
	}
}
/////////////////////////////////////////////Add new book or user
void Add(int tab, string filename) {																	//add user or book
																										//const char * file = "Book.dat";
																										//const char * file1 = "User.dat";
	string file = filename;
	Book book;
	User user;
	char buf[200];
	int temp;

	if (tab == 0) {
		ofstream fout(file,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout.is_open())
		{

			SetConsoleCursorPosition(2, 41);
			ClearRow();
			cerr << "Can't open " << file << " file for output:\t\t\t\t\t\n";
			exit(EXIT_FAILURE);
		}

		SetConsoleCursorPosition(2, 41);
		cout << "Enter book name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.B_name, 110);

		while (strlen(book.B_name) > 100)
		{
			SetConsoleCursorPosition(2, 41);
			cout << "Enter book name (max - 100):\t\t\t\t\t\n";
			ClearRow();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(book.B_name, 110);
		}

		if (book.B_name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			return;
		}
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Author Name ->Format Name Surname Patronymic:\t\t\t\t\t\n";
		ClearRow();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(book.Aut, 40);

		while (strlen(book.Aut) > 36)
		{
			SetConsoleCursorPosition(2, 41);
			cout << "Enter Author Name ->(max - 33):\t\t\t\t\t\n";
			ClearRow();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(book.Aut, 40);
		}

		if (book.Aut[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Release date ->Format dd.mm.yyyy:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.R_date, 100);
									
		while(strlen(book.R_date)>10)		//chek leng
		{SetConsoleCursorPosition(2, 41);
		cout << "Enter Release date ->Format dd.mm.yyyy:\t\t\t\t\t\n";
		ClearRow();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(book.R_date, 100);	}				 //temp

		if (book.R_date[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book context:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.Con, 30);
		if (book.Con[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream


		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book count:\t\t\t\t\t\n";
		ClearRow();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1>temp || temp>11)
		{

			SetConsoleCursorPosition(2, 41);
			cout << "Erorr! Enter an integer between 1 and 10, inclusive:\t\t\t\n";
			ClearRow();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		book.Cou = temp;

		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book rate:\t\t\t\t\t\n";
		ClearRow();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (0>temp || temp>11)
		{

			SetConsoleCursorPosition(2, 41);
			cout << "Erorr! Enter an integer between 0 and 5, inclusive.\t\t\t\n";
			ClearRow();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		book.Rat = temp;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book ID:\t\t\t\t\t\n";
		ClearRow();
		cin >> book.ID_b;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		if (book.B_name[0] != '\0')
			fout.write((char *)&book, sizeof book);
		fout.close();
	}

	else {
		ofstream fout(file,
			ios_base::out | ios_base::app | ios_base::binary);
		//NOTE: some systems don't accept the ios::binary mode
		if (!fout.is_open())
		{

			SetConsoleCursorPosition(2, 41);
			ClearRow();
			cerr << "Can't open " << file << " file for output:\t\t\t\t\t\n";
			exit(EXIT_FAILURE);
		}

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Member name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(user.U_Name, 30);
		if (user.U_Name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			return;
		}

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter birthday user  format (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.Hbir, 11);
		if (user.Hbir[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Date of issue  format dd.mm.yyyy (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.DateIs, 11);
		if (user.DateIs[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		SetConsoleCursorPosition(2, 41);
		cout << "Enter ID-user format 0000 (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.ID_vs_ID, 5);
		if (user.ID_vs_ID[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		if (user.U_Name[0] != '\0')
			fout.write((char *)&user, sizeof user);
		fout.close();
	}

	SetConsoleCursorPosition(2, 41);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
	ClearRow();
	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());
}

/////////////////////////////////////////////Random line edit book or user
void RandomLineEdit(int tab, string filename) {								  //not work user block
	string file = filename;
	Book book;
	User user;
	char buf[16];
	int ct = 0;
	long rec;
	int temp;

	fstream finout;     // read and write streams
	finout.open(filename,
		ios_base::in | ios_base::out | ios_base::binary);
	//NOTE: Some Unix systems require omitting | ios::binary

	if (finout.is_open()) {
		finout.seekg(0);    // go to beginning
							//cout << "Here are the current contents of the "
							//	<< file1 << " file1:\n";

		if (tab == 0) {
			while (finout.read((char *)&book, sizeof book))
				ct++;
		}
		
		else {
			while (finout.read((char *)&user, sizeof user))
				ct++;
		}

		if (finout.eof())
			finout.clear(); // clear eof flag
		else {
			SetConsoleCursorPosition(2, 41);
			cerr << "Error in reading " << filename << ".\t\t\t\t\t\t\n";
			ClearRow();
			
			return;
		}
	}
	else
	{
		SetConsoleCursorPosition(2, 41);
		cerr << filename << " could not be opened -- bye.\t\t\t\t\t\t\n";
		ClearRow();
		
		return;
	}


	SetConsoleCursorPosition(2, 41);
	cout << "Enter the record number you wish to change: \t\t\t\t\t\t\n";
	ClearRow();
	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
	cin >> rec;

	eatline();                                      // get rid of newline		


	if (rec < 0 || rec >= ct) {
		
		SetConsoleCursorPosition(2, 41);
		cerr << "Invalid record number \t\t\t\t\t\t\n";
		ClearRow();
		return;
	}
	if (tab == 0) {	   // convert to streampos type
		streampos place = rec * sizeof book;
		finout.seekg(place);
		finout.read((char *)&book, sizeof book);
		SetConsoleCursorPosition(2, 41);
		cout << "Your selection:\t\t\t\t\t\t\n";
		ClearRow();
														  //readfile
		cout << rec << ": " << setw(20) << book.B_name << ": "
			<< setprecision(0) << setw(12) << book.Aut
			<< setprecision(2) << setw(6) << book.Con << endl;

		if (finout.eof())
			finout.clear();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter book name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.B_name, 30);
		if (book.B_name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Author Name ->Format Name Surname Patronymic:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.Aut, 100);
		if (book.Aut[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Release date ->Format dd.mm.yyyy:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.R_date, 11);
		if (book.R_date[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book context:\t\t\t\t\t\n";
		ClearRow();
		cin.get(book.Con, 30);
		if (book.Con[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream


		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book count:\t\t\t\t\t\n";
		ClearRow();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1 > temp || temp > 11 || !atoi(buf)) {

			SetConsoleCursorPosition(2, 41);
			cout << "Erorr! Enter an integer between 1 and 10, inclusive:\t\t\t\n";
			ClearRow();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		book.Cou = temp;

		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book rate:\t\t\t\t\t\n";
		ClearRow();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (0 > temp || temp > 11||!atoi(buf)) {
			SetConsoleCursorPosition(2, 41);
			cout << "Erorr! Enter an integer between 0 and 5, inclusive.\t\t\t\n";
			ClearRow();
			cin.getline(buf, 5);
			temp = atoi(buf);
		}

		book.Rat = temp;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Book ID:\t\t\t\t\t\n";
		ClearRow();
		cin >> book.ID_b;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream


		finout.read((char *)&user, sizeof user);		  ////temp chec
		SetConsoleCursorPosition(2, 55);
		cout << "Your selection:\t\t\t\t\t\t\n";
		cout << rec << ": " << setw(20) << user.U_Name << ": "
			<< setprecision(0) << setw(12) << user.Hbir
			<< setprecision(2) << setw(6) << user.DateIs << endl;
		///////////////temp zamena na readFile	???? info line



		if (finout.eof())
			finout.clear();     // clear eof flag
		finout.seekp(place);    // go back
		finout.write((char *)&book, sizeof book) << flush;
		if (finout.fail()) {
			SetConsoleCursorPosition(2, 41);
			cerr << "Error on attempted write\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}
	}
	else {			// convert to streampos type

		streampos place1 = rec * sizeof user;
		finout.seekg(place1);

		// random access
		if (finout.fail()) {
			SetConsoleCursorPosition(2, 41);
			cerr << "Error on attempted seek\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}

		///////////////////temp

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Member name (enter a blank line to quit):\t\t\t\t\t\n";
		ClearRow();
		cin.get(user.U_Name, 30);
		if (user.U_Name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		SetConsoleCursorPosition(2, 41);
		cout << "Enter birthday user  format (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.Hbir, 11);
		if (user.Hbir[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		SetConsoleCursorPosition(2, 41);
		cout << "Enter Date of issue  format dd.mm.yyyy (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.DateIs, 11);
		if (user.DateIs[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		SetConsoleCursorPosition(2, 41);
		cout << "Enter ID-user format 0000 (enter a blank line to quit):\t\t\t\n";
		ClearRow();
		cin.get(user.ID_vs_ID, 5);
		if (user.ID_vs_ID[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		finout.seekp(place1);    // go back
		finout.write((char *)&user, sizeof user) << flush;

		if (finout.fail()) {
			SetConsoleCursorPosition(2, 41);
			cerr << "Error on attempted write\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}
	}
	finout.close();
	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());

	SetConsoleCursorPosition(2, 41);
	cout << "Edite Done.\t\t\t\t\t\t\n";
	ClearRow();

	
}
	


//void SaveFile() {			   ///not work corect  !!!!!!!!!!!!!!!!!!!
//	const char * file = "Book.dat";
//	const char * file1 = "User.dat";
//	Book book;
//	User user;
//
//		ofstream fout_B(file,
//			ios_base::out | ios_base::app | ios_base::binary);			//NOTE: some systems don't accept the ios::binary mode
//		if (!fout_B.is_open())
//		{
//			//ClearRow();
//			//SetConsoleCursorPosition(2, 41);
//			FullClearRow(41);
//			SetConsoleCursorPosition(2, 41);
//			cerr << "Can't open " << file << " file for output:"<<endl;
//			exit(EXIT_FAILURE);
//		}
//
//		fout_B.write((char *)&book, sizeof book);
//
//		//ClearRow();
//		//SetConsoleCursorPosition(2, 41);
//		FullClearRow(41);
//		SetConsoleCursorPosition(2, 41);
//		cout << "Save->" << file << endl;
//		fout_B.close();
//
//		ofstream fout_U(file1,
//			ios_base::out | ios_base::app | ios_base::binary);
//		//NOTE: some systems don't accept the ios::binary mode
//		if (!fout_U.is_open())
//		{
//			//ClearRow();
//			//SetConsoleCursorPosition(2, 42);
//			FullClearRow(42);
//			SetConsoleCursorPosition(2, 42);
//			cerr << "Can't open ->" << file1 << " file for output:"<<endl;
//			exit(EXIT_FAILURE);
//		}
//
//
//		fout_U.write((char *)&user, sizeof user);
//
//		//ClearRow();
//		//SetConsoleCursorPosition(2, 42);
//		FullClearRow(42);
//		SetConsoleCursorPosition(2, 42);
//		cout << "Save->" << file1 << endl;
//
//		fout_U.close();
//
//}
//void SaveFile1() {
//	const char * file = "Book.dat";
//	const char * file1 = "User.dat";
//	Book book;
//	User user;
//
//	ofstream fout_B(file,
//		ios_base::out | ios_base::app | ios_base::binary);			//NOTE: some systems don't accept the ios::binary mode
//	if (!fout_B.is_open())
//	{
//		
//		cerr << "Can't open " << file << " file for output:" << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	fout_B.write((char *)&book, sizeof book);
//	fout_B.close();
//
//	ofstream fout_U(file1,
//		ios_base::out | ios_base::app | ios_base::binary);
//	//NOTE: some systems don't accept the ios::binary mode
//	if (!fout_U.is_open())
//	{
//		FullClearRow(42);
//		SetConsoleCursorPosition(2, 42);
//		cerr << "Can't open ->" << file1 << " file for output:" << endl;
//		exit(EXIT_FAILURE);
//	}
//
//
//	fout_U.write((char *)&user, sizeof user);
//
//	fout_U.close();
//
//}
//void OpenFile(string filename, int tab){
//string file =  filename ;
//Book book;
//User user;
//
//
//if (tab = 0) {
//	ifstream fin_B;
//
//	fin_B.open(file, ios_base::in | ios_base::binary);		// binary file
//
//	if (fin_B.is_open()) {
//				
//		FullClearRow(41);
//		SetConsoleCursorPosition(15, 3);
//		cout <<  file << " open:\n";
//		SetConsoleCursorPosition(0, 5);
//		while (fin_B.read((char *)&book, sizeof book)) {
//
//			cout << setiosflags(ios::left);					//viravnivanie
//			cout << char(186) << setw(20) << book.B_name;
//			cout << '|' << setw(5) << book.ID_b;
//			cout << '|' << setw(3) << book.Cou << endl;
//		}
//		fin_B.close();
//
//	}
//	else {
//		FullClearRow(41);
//		SetConsoleCursorPosition(60, 3);
//		cout << "- Error open file->" << file << endl;
//	}
//	fin_B.close();
//}
//   else{
//	  
//		ifstream fin_U;
//		fin_U.open(file, ios_base::in | ios_base::binary);		// binary file
//		int i = 5;														//NOTE: some systems don't accept the ios_base::binary mode
//		if (fin_U.is_open()) {
//			FullClearRow(42);
//			SetConsoleCursorPosition(1, 42);
//			cout <<  file << " file:\n";
//
//			fin_U.read((char *)&user, sizeof user);
//			SetConsoleCursorPosition(51, i);
//			cout << setiosflags(ios::left);
//			cout << setw(15) << user.U_Name << '|' << setw(10) << user.Hbir << endl;
//			//cout << '|' << setw(11) << user.DateIs;
//			//cout << '|' << setw(11) << user.Pas << endl;
//			i++;
//		}
//		else {
//			FullClearRow(42);
//			SetConsoleCursorPosition(2, 42);
//			cout << "Error open file->" << file << endl;
//
//		}
//		fin_U.close();
//	 }
//}





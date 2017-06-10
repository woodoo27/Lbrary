#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <cstdlib> 
#include <conio.h>	 //console
#include "My_Lib.h"


//////////////////////////////////////////////Create new file
void Filename(int tab, string filename) {				
	ofstream fout(filename.c_str());  // create output stream object for new file and call it fout
	fout.close();
	SetConsoleCursorPosition(2, 41);
	cout << "New file name ->"<<filename<<"\t\t\t\t\t\n";// close file
	fout.clear();
	fout.close();
	return;
}

//////////////////////////////////////////////Read file
void ReadMyFile(int tab, string filename) {
	int str = 1;
	string file = filename;
	int x = 0;
	int y = 0;
	Book book;
	User user;
	int nrow = 0;

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
			/*exit(EXIT_FAILURE);*/
			return;
		}
		MassageBook_1();
		cin.get(book.B_name, 110);

		while (strlen(book.B_name) > 100)
		{
			MassageBook_2();
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

		MassageBook_3();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(book.Aut, 110);

		while (strlen(book.Aut) > 100)
		{
			MassageBook_4();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(book.Aut, 110);
		}

		if (book.Aut[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_5();
		cin.get(book.R_date, 15);
									
		while(strlen(book.R_date)>10)		//chek leng
		{SetConsoleCursorPosition(2, 41);

		MassageBook_5();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(book.R_date, 15);	}				 //temp

		if (book.R_date[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_6();
		cin.get(book.Con, 35);

		while (strlen(book.Con) > 30) {

			MassageBook_7();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(book.Con, 35);
		}


		if (book.Con[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_8();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1>temp || temp>11 || !atoi(buf))
		{
			MassageBook_9();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		book.Cou = temp;

		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_10();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (0>temp || temp>5 || !atoi(buf))
		{
			MassageBook_11();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		book.Rat = temp;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_12();
		cin.getline(buf,10);
		temp = atoi(buf);

		while (0>temp || temp>9999 || !atoi(buf))
		{
			MassageBook_13();
			cin.getline(buf, 10);
			temp = atoi(buf);

		} 
		book.ID_b = temp;
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
			//exit(EXIT_FAILURE);
			return;
		}
		MassageMem_1();
		cin.get(user.U_Name, 110);

		while (strlen(user.U_Name) > 100)
		{
			MassageMem_5();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(user.U_Name, 110);
		}

		if (user.U_Name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			return;
		}

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageMem_2();
		cin.get(user.Hbir, 11);
		if (user.Hbir[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_3();
		cin.get(user.DateIs, 11);
		if (user.DateIs[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_4();
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
		ios_base::in | ios_base::out | ios_base::binary);		//NOTE: Some Unix systems require omitting | ios::binary

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

	MassageFile_1();
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

		MassageFile_3();
														  //readfile
		cout << rec << ": " << setw(20) << book.B_name << ": "
			<< setprecision(0) << setw(12) << book.Aut
			<< setprecision(2) << setw(6) << book.Con << endl;

		if (finout.eof())
			finout.clear();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_1();


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

		MassageBook_3();
		cin.get(book.Aut, 100);
		if (book.Aut[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_5();
		cin.get(book.R_date, 11);
		if (book.R_date[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
		
		MassageBook_6();
		cin.get(book.Con, 30);
		if (book.Con[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_8();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1 > temp || temp > 11 || !atoi(buf)) {

			MassageBook_9();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		book.Cou = temp;

		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_10();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (0 > temp || temp > 11||!atoi(buf)) {
			MassageBook_11();
			cin.getline(buf, 5);
			temp = atoi(buf);
		}

		book.Rat = temp;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_12();
		cin >> book.ID_b;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream


		finout.read((char *)&user, sizeof user);		  ////temp chec
		SetConsoleCursorPosition(2, 55);
		cout << "Your selection:\t\t\t\t\t\t\n";
		cout << setiosflags(ios::left);					//viravnivanie
		cout << char(186) << setw(20) << book.B_name;
		cout << '|' << setw(20) << book.Aut;
		cout << '|' << setw(10) << book.R_date;
		cout << '|' << setw(20) << book.Con;
		cout << '|' << setw(2) << book.Rat;
		cout << '|' << setw(5) << book.ID_b;
		cout << '|' << setw(3) << book.Cou << endl;
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

		MassageMem_1();
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

		MassageMem_2();
		cin.get(user.Hbir, 11);
		if (user.Hbir[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_3();
		cin.get(user.DateIs, 11);
		if (user.DateIs[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_4();
		cin.get(user.ID_vs_ID, 5);
		if (user.ID_vs_ID[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());


		MassageMem_7();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1 > temp || temp > 9999 || !atoi(buf)) {

			MassageMem_8();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		user.Pas = temp;

		eatline();




		finout.seekp(place1);    // go back
		finout.write((char *)&user, sizeof user) << flush;

		SetConsoleCursorPosition(2, 55);
		cout << "Your selection:\t\t\t\t\t\t\n";
		cout << setiosflags(ios::left);
		SetConsoleCursorPosition(0, 5);
		cout << setiosflags(ios::left);
		cout << char(186)  << setw(20) << user.U_Name;
		cout << '|' << setw(11) << user.Hbir;
		cout << '|' << setw(11) << user.DateIs;
		cout << '|' << setw(20) << user.ID_vs_ID << endl;
		cout << '|' << setw(20) << user.Pas << endl;
		cout  << setw(13) <<  char(186) << endl;

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

	MassageMem_9();

	
}

void ReadMyFule(int tab, string filename) {
	string file = filename;
	int x = 0;
	int y = 0;
	Book book;
	User user;
	int nrow = 0;

	if (tab == 0) {
		ifstream fin;
		fin.open(file, ios_base::in | ios_base::binary);		// binary file
																//NOTE: some systems don't accept the ios_base::binary mode
		if (fin.is_open()) {
			SetConsoleCursorPosition(10, 3);
			cout << setw(30) << file << " - open";

			
			SetConsoleCursorPosition(0, 5);
			while (fin.read((char *)&book, sizeof book)) {
				
				cout << setiosflags(ios::left);					//viravnivanie
				cout << char(186) << setw(3) << nrow++ << ":" << setw(20) << book.B_name;
				cout << '|' <<setw(20) << book.Aut ;
				cout << '|' << setw(10) << book.R_date;
				cout << '|' << setw(20) << book.Con ;
				cout << '|' << setw(2) << book.Rat;
				cout << '|' << setw(5) << book.ID_b;
				cout << '|' << setw(3) << book.Cou << endl;
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

			SetConsoleCursorPosition(0, 5);
			while (fin.read((char *)&user, sizeof user)) {

				SetConsoleCursorPosition(0,5);
				cout << setiosflags(ios::left);
				cout << char(186) << setw(3) << nrow++ << ":" << setw(20) << user.U_Name;
				cout << '|' << setw(11) << user.Hbir ;
				cout << '|' << setw(11) << user.DateIs;
				cout << '|' << setw(20) << user.ID_vs_ID << endl;
				cout << '|' << setw(20) << user.Pas << endl;
			}  nrow = 0;
			fin.close();
		}
	}
}

void EditID(int tab, string filename) {
	string file = filename;
	Book book;
	User user;
	char buf[16];
	int ct = 0;
	long rec;
	int temp;
	streambuf *bak;

	fstream finout;     // read and write streams
	finout.open(filename,
		ios_base::in | ios_base::out | ios_base::binary);	//NOTE: Some Unix systems require omitting | ios::binary

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
	MassageFile_4();
	cin >> rec;

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());



	if (rec < 0 || rec >= ct) {

		MassageFile_5();
		return;
	}	
	streampos place; 
	streampos place1;
	if (tab == 0) {	   // convert to streampos type


		streampos place = ct * sizeof book;
		finout.seekg(place);
		finout.read((char *)&book, sizeof book);


		if (finout.eof())
			finout.clear();
		//
		streampos place1 = rec * sizeof book;				  //change delete row with last
				finout.seekp(place1);    // go back
				finout.write((char *)&book, sizeof book)<< flush;
		
				place1 = ct;
				finout.seekp(place1);    // go back
				finout.put(EOF) ;

		if (finout.eof())
			finout.clear();
			 finout.close();

		if (finout.fail()) {
			SetConsoleCursorPosition(2, 41);
			cerr << "Error on attempted write\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}
	}
	else {												//for user
	}
	
}


void Del(int tab, string filename) {				 ////////////////????????????????????
	string file = filename;
	string ftemp = "temp_file";
	Book book;
	User user;
	char buf[16];
	int ct = 0;
	long rec;
	int temp;
	streambuf *bak;

	Filename(tab, ftemp);
	fstream finout;     // read and write streams
	finout.open(filename,
		ios_base::in | ios_base::out | ios_base::binary);	//NOTE: Some Unix systems require omitting | ios::binary

	fstream finout_temp;
	finout_temp.open(ftemp,
		ios_base::in | ios_base::out | ios_base::binary);
	
	
	MassageFile_4();
	cin >> rec;


	if (finout.is_open()) {
		
																		//dobavinm obrabotku finout_temp.is_open!!!!!!!
		if (tab == 0) {												//rabotaet
			while (finout.read((char *)&book, sizeof book)) {
				
				if (ct != rec) {
					finout_temp.write((char *)&book, sizeof book);
				finout.clear();
				finout_temp.clear();
			}
				else
					ct++; 
				ct++;
			}
		}

		else {
			while (finout.read((char *)&user, sizeof user)) {

				if (ct != rec) {
					finout_temp.write((char *)&user, sizeof user);
					finout.clear();
					finout_temp.clear();
				}
				else
					ct++;
				ct++;
			}
		}															//vnutr finout_temp.is_open()
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

	finout.clear();
	finout.close();
	finout_temp.clear();
	finout_temp.close();
	//CopyFile_my(tab,filename);
	  	//NOTE: some systems don't accept the ios::binary mode

	


	//if (finout_temp.is_open())
	//{

	//	if (tab == 0) {

	//		// convert to streampos type


	//		
	//		finout.seekg(place);
	//		finout.read((char *)&book, sizeof book);


	//		if (finout.eof())
	//			finout.clear();
	//		//
	//						  //change delete row with last
	//		finout.seekp(place1);    // go back
	//		finout_temp.write((char *)&book, sizeof book) << flush;

	//		place1 = ct;
	//		finout.seekp(place1);    // go back
	//		finout_temp.put(EOF);

	//		if (finout.eof())
	//			finout.clear();
	//		finout.close();

	//		if (finout.fail()) {
	//			SetConsoleCursorPosition(2, 41);
	//			cerr << "Error on attempted write\t\t\t\t\t\t\n";
	//			ClearRow();
	//			return;
	//		}
	//	}
	//}
	//else
	//{
	//	SetConsoleCursorPosition(2, 41);
	//	cerr << ftemp << " could not be opened -- bye.\t\t\t\t\t\t\n";
	//	ClearRow();
	//	return;
	//}
	//finout_temp.close;
	//finout.close;
}





/////////////////////  bufer
//std::fstream src,dest;
//src.open("test.txt");
//dest.open("copy.txt");
//
//std::filebuf* inbuf = src.rdbuf();
//std::filebuf* outbuf = dest.rdbuf();
//
//char c = inbuf->sbumpc();
//while (c != EOF)
//{
//	outbuf->sputc(c);
//	c = inbuf->sbumpc();
//}
//
//dest.close();
//src.close();
//
//return 0;
 ////////////////////////end bufer



void CopyFile_my(int tab, string filename) {
	string file = filename;
	string ftemp = "temp_file";
	Book book;
	User user;
	int ct = 0;
	long rec;
	streampos place;

	fstream finout;     // read and write streams
	finout.open(filename,
		ios_base::in | ios_base::out | ios_base::trunc | ios_base::binary);	//NOTE: Some Unix systems require omitting | ios::binary

	fstream finout_temp;
	finout_temp.open(ftemp,
		ios_base::in | ios_base::out | ios_base::binary);

	if (finout.is_open()) {															//vnutr finout_temp.is_open()


		if (tab == 0) {												//rabotaet	   
			while (finout_temp.read((char *)&book, sizeof book)) {

				
					finout.write((char *)&book, sizeof book);
					finout.clear();
					finout_temp.clear();
				
			}
		}

		else {
			while (finout_temp.read((char *)&user, sizeof user)) {

				
					finout.write((char *)&user, sizeof user);
					finout.clear();
					finout_temp.clear();
				
			}
		}
		finout.eof();
		if (finout.eof())											 ///????????????????????????
			finout.clear(); // clear eof flag
		else {
			SetConsoleCursorPosition(2, 41);
			cerr << "Error in reading copy " << filename << ".\t\t\t\t\t\t\n";
			ClearRow();
			return;
		}
	}
	else
	{
		SetConsoleCursorPosition(2, 41);
		cerr << filename << "copy could not be opened -- bye.\t\t\t\t\t\t\n";
		ClearRow();
		return;
	}

	finout.clear();
	finout.close();
	finout_temp.clear();
	finout_temp.close();



}






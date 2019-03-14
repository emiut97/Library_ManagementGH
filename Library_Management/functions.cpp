#pragma once
#include "standard_includes.h"
#include "classes.h"
#include "console_functions_LEGACY.h"
#include "functions.h"
#include "console_functions_LEGACY.h"

void create_a_library()
{
	cls();
	print_vasat("A NEW LIBRARY!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;

	library  temp;

	print_in_color("> Enter a name for the new library (NO WHITESPACES!): ", "def", "yellow");
	string s;
	cin >> s;
	temp.set_name(s);
	cout << endl;
	print_in_color("> Enter an address for the new library (10 Characters): ", "def", "yellow");
	char c[10];
	cin >> c;
	temp.set_address(c);

	string fadd = "./text_folder2/booklistof_" + temp.get_name() + "_" + temp.get_address() + ".txt";
	ofstream new_file(fadd, ios::app); //possible bug
	new_file.close();
	///Adding to the libraries.txt
	ofstream libs("./text_folder/libraries.txt", ios::app);
	libs << endl << temp.get_name() << "\t" << temp.get_address() << "\t" << temp.get_deleted();
	libs.close();

	//TODO (optional): showing the info after a cls() right here...

	cout << endl << endl << endl;
	print_vasat("Library successfully created!", "def", "green", console_columns_count());
	cout << endl;
	leaving_in(6, "def", "yellow");
}

//placeholder baraye morede 2

void create_a_book()
{
	cls();
	print_vasat("A NEW BOOK!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;

	book  temp;

	print_in_color("> Enter an ISBN for the new book (NO WHITESPACES!/10 Characters): ", "def", "yellow");
	char* c;
	cin >> c;
	temp.set_ISBN(c);
	cout << endl;

	print_in_color("> Enter a NAME for the new book (NO WHITESPACES!/18 Characters): ", "def", "yellow");
	cin >> c;
	temp.set_name(c);

	print_in_color("> Enter an AUTHOR name for the new book (NO WHITESPACES!/18 Characters): ", "def", "yellow");
	string s;
	cin >> s;
	temp.set_author(s);

	print_in_color("> Enter a GENRE for the new book : ", "def", "yellow");
	s = "Fantasy";
	temp.set_genre(s); //

	string fadd = "./text_folder2/booklistof_" + temp.get_name() + "_" + temp.get_address() + ".txt";
	ofstream new_file(fadd, ios::app); //possible bug
	new_file.close();
	///Adding to the libraries.txt
	ofstream libs("./text_folder/libraries.txt", ios::app);
	libs << endl << temp.get_name() << "\t" << temp.get_address() << "\t" << temp.get_deleted();
	libs.close();

	//TODO (optional): showing the info after a cls() right here...

	cout << endl << endl << endl;
	print_vasat("Library successfully created!", "def", "green", console_columns_count());
	cout << endl;
	leaving_in(6, "def", "yellow");
}

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
	ofstream new_file(fadd, ios::app);
	new_file.close();
	///Adding to the libraries.txt
	ofstream libs("./text_folder/libraries.txt", ios::app);
	libs << endl << temp.get_name() << "\t" << temp.get_address() << "\t" << temp.get_deleted();
	libs.close();


	cout << endl << endl << endl;
	print_vasat("Library successfully created!", "def", "green", console_columns_count());

	//TODO (optional): showing the info after a cls() right here...

	cout << endl;
	leaving_in(6, "def", "yellow");
}

void add_a_book_to_a_library()
{
	//INITS
	library  vlib;
	vlib.set_name("NOTFOUND");

	book vbook;
	vbook.set_author("NOTFOUND");

	//TODO ali: use assign_book_to_library() ...

	cls();
	print_vasat("ADD A BOOK TO A LIBRARY!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;

	char vaddress[10];
	print_in_color("> Enter the ADDRESS of the library (10 Characters): ", "def", "yellow");
	cin >> vaddress;

	ifstream inlib("./text_folder/libraries.txt");

	while (inlib.good())
	{
		library temp(inlib);
		bool same = true;
		for (int i = 0; i < 10; ++i)
		{
			if (temp.get_address()[i] != vaddress[i])
			{
				same = false;
			}
		}
		if (same)
		{
			vlib = temp;
		}
	}
	inlib.close();
	if (vlib.get_name() == "NOTFOUND")
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("LIBRARY NOT FOUND!", "def", "red");
		cout << endl;
		leaving_in(4, "def", "red");
		return; //FUNCTION ENDS HERE
	}

	bool tryagain = true;
	while (tryagain)
	{
		cout << endl;
		char vISBN[11] = { 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z' };
		char vname[19] = { '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,
			'~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' };
		cout << endl;
		print_in_color("> Enter the ISBN of the book (10 Characters): ", "def", "yellow");
		cin >> vISBN;
		cout << endl;
		print_in_color("> Enter the NAME of the book (18 Characters): ", "def", "yellow");
		cin >> vname;


		ifstream inbook("./text_folder/books.txt");
		while (inbook.good())
		{
			book temp(inbook);
			bool same = true;
			for (int i = 0; i < 10 && vISBN[i] != 'z' && vISBN[i] != '\0'; ++i)
			{
				if (temp.get_ISBN()[i] != vISBN[i])
				{
					same = false;
				}
			}
			for (int i = 0; i < 10 && vname[i] != '~' && vname[i] != '\0'; ++i)
			{
				if (temp.get_name()[i] != vname[i])
				{
					same = false;
				}
			}
			if (same)
			{
				vbook = temp;
			}
		}
		inbook.close();
		if (vbook.get_author() == "NOTFOUND")
		{
			cout << endl;
			print_line_in_color(console_columns_count(), "red");
			cout << endl;
			print_in_color("BOOK NOT FOUND!", "def", "red");
			cout << endl;

			char ans;
			print_in_color("Try again? (y/n)", "def", "yellow");
			cin >> ans;
			if (ans == 'y' || ans == 'Y')
				tryagain = true;
			else
				tryagain = false;
		}
	}


	assign_book_to_library(vbook, vlib);
	cout << endl;
	print_vasat("OPERATION SUCCESSFUL!", "def", "green", console_columns_count());
	cout << endl;
	leaving_in(6, "def", "yellow");
}

void create_a_book()
{
	cls();
	print_vasat("A NEW BOOK!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;

	book  temp;

	print_in_color("> Enter an ISBN for the new book (NO WHITESPACES!/10 Characters): ", "def", "yellow");
	char* c;
	cin >> c; //possible bug ali: mishe aslan char* gereft o injoori rikht toosh???
	temp.set_ISBN(c);
	cout << endl;

	print_in_color("> Enter a NAME for the new book (NO WHITESPACES!/18 Characters): ", "def", "yellow");
	cin >> c;
	temp.set_name(c);

	print_in_color("> Enter an AUTHOR name for the new book (NO WHITESPACES!/18 Characters): ", "def", "yellow");
	string s;
	cin >> s;
	temp.set_author(s);

	//example for ali seraj (enum as a type!)
	print_in_color("> Enter a GENRE for the new book ", "def", "yellow");
	cout << endl;
	print_in_color("(Fantasy/Westerns/Romance/Thriller/Mystery/Detective_Story/Biography/Musical)", "def", "yellow");
	cout << endl;
	print_in_color("> : ", "def", "yellow");
	cin >> s;
	while (temp.set_genre(s))
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("INVALID INPUT!", "def", "red");
		print_in_color(">Try again: ", "def", "yellow");
		cin >> s;
	}

	///Adding to the books.txt
	ofstream books("./text_folder/books.txt", ios::app);
	books << endl
		<< temp.get_ISBN() << "\t"
		<< temp.get_name() << "\t"
		<< temp.get_author() << "\t"
		<< temp.get_genre() << "\t"
		<< temp.get_loaned() << "\t"
		<< temp.get_deleted();

	books.close();

	cout << endl << endl << endl;
	print_vasat("Book successfully created!", "def", "green", console_columns_count());

	//TODO (optional): showing the info after a cls() right here...

	cout << endl;
	leaving_in(6, "def", "yellow");
}

void loan_return_a_book()
{
	cls();
	print_vasat("LOAN/RETURN A BOOK!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;

	/*TODO ali:
	1) 2ta ifstream ba address haayi ke tooye
	create_a_library va create_a_book hastand
	besaz.
	2) ye object az library va yeki az book besaz
	khode ina constructor darand ke ifstream begire.
	check kon bebin akharin version bashe baraye hardo (replace)
	3) bebin ba input aaa mikhore
	4) age nemikhored-> peyghame monaseb. (use console_functions_LEGACY.h functions)
	5) age mikhord-> check kon tooye file haaye "booklistof"
	bebin asan hamchin bookio dare in library ya na
	***NOKTE: tooye booklist of faghat 'ISBN' va 'name' hastand (delimiter: \t)
	6) age nadasht-> peyghaame monaseb
	7) age dasht-> loaned esho avaz kon va befrest baraye assign_book_to_library()
	*/



	//INITS
	library  vlib;
	vlib.set_name("NOTFOUND");

	book vbook;
	vbook.set_author("NOTFOUND");

	//TODO ali: use assign_book_to_library() ...


	char vaddress[10];
	print_in_color("> Enter the ADDRESS of the library (10 Characters): ", "def", "yellow");
	cin >> vaddress;

	ifstream inlib("./text_folder/libraries.txt");

	while (inlib.good())
	{
		library temp(inlib);
		bool same = true;
		for (int i = 0; i < 10; ++i)
		{
			if (temp.get_address()[i] != vaddress[i])
			{
				same = false;
			}
		}
		if (same)
		{
			vlib = temp;
		}
	}
	inlib.close();
	if (vlib.get_name() == "NOTFOUND")
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("LIBRARY NOT FOUND!", "def", "red");
		cout << endl;
		leaving_in(4, "def", "red");
		return; //FUNCTION ENDS HERE
	}

	bool tryagain = true;
	while (tryagain)
	{
		cout << endl;
		char vISBN[11] = { 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z' };
		cout << endl;
		print_in_color("> Enter the ISBN of the book (10 Characters): ", "def", "yellow");
		cin >> vISBN;


		ifstream inbook("./text_folder/books.txt");
		while (inbook.good())
		{
			book temp(inbook);
			bool same = true;
			for (int i = 0; i < 10 && vISBN[i] != 'z' && vISBN[i] != '\0'; ++i)
			{
				if (temp.get_ISBN()[i] != vISBN[i])
				{
					same = false;
				}
			}
			if (same)
			{
				vbook = temp;
			}
		}
		inbook.close();
		if (vbook.get_author() == "NOTFOUND")
		{
			cout << endl;
			print_line_in_color(console_columns_count(), "red");
			cout << endl;
			print_in_color("BOOK NOT FOUND!", "def", "red");
			cout << endl;
			char ans;
			print_in_color("Try again? (y/n)", "def", "yellow");
			cin >> ans;
			if (ans == 'y' || ans == 'Y')
				tryagain = true;
			else
				tryagain = false;
		}

	}

	//search in booklistof e hamoon library ke bebinim asan toosh hast ya nist age bood ! konim.

	string fadd = "./text_folder2/booklistof_" + vlib.get_name() + "_" + vlib.get_address() + ".txt";
	ifstream curr_list(fadd);
	//curr_list << endl << vbook.get_ISBN() << "\t" << vbook.get_name() << "\t" << vbook.get_loaned();
	bool exists = true;
	while (curr_list.good())
	{
		book temp(curr_list);
		bool same = true;
		for (int i = 0; i < 10 && vbook.get_ISBN()[i] != 'z' && vbook.get_ISBN()[i] != '\0'; ++i)
		{
			if (temp.get_ISBN()[i] != vbook.get_ISBN()[i])
			{
				same = false;
			}
		}
		for (int i = 0; i < 10 && vbook.get_name()[i] != '~' && vbook.get_name()[i] != '\0'; ++i)
		{
			if (temp.get_name()[i] != vbook.get_name()[i])
			{
				same = false;
			}
		}
		if (same)
		{
			exists = true;
		}
	}
	curr_list.close();
	//if nabood-> return
	if (!exists)
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("BOOK DOESN'T BELONG TO THE LIBRARY!", "def", "red");
		return;
	}

	vbook.set_loaned(!vbook.get_loaned());
	assign_book_to_library(vbook, vlib);
	cout << endl;
	print_vasat("OPERATION SUCCESSFUL!", "def", "green", console_columns_count());
	cout << endl;
	leaving_in(6, "def", "yellow");
}

void list_by_a_specific_genre() //TODO ali:
{
	cls();
	print_vasat("LIST BY A SPECIFIC GENRE!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;


	library  vlib;
	vlib.set_name("NOTFOUND");


	char vaddress[10];
	print_in_color("> Enter the ADDRESS of the library (10 Characters): ", "def", "yellow");
	cin >> vaddress;

	ifstream inlib("./text_folder/libraries.txt");

	while (inlib.good())
	{
		library temp(inlib);
		bool same = true;
		for (int i = 0; i < 10; ++i)
		{
			if (temp.get_address()[i] != vaddress[i])
			{
				same = false;
			}
		}
		if (same)
		{
			vlib = temp;
		}
	}
	inlib.close();
	if (vlib.get_name() == "NOTFOUND")
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("LIBRARY NOT FOUND!", "def", "red");
		cout << endl;
		leaving_in(4, "def", "red");
		return; //FUNCTION ENDS HERE
	}


	string s;
	print_in_color("> Enter a GENRE ", "def", "yellow");
	cout << endl;
	print_in_color("(Fantasy/Westerns/Romance/Thriller/Mystery/Detective_Story/Biography/Musical)", "def", "yellow");
	cout << endl;
	print_in_color("> : ", "def", "yellow");
	cin >> s;
	book compare;
	while (!compare.set_genre(s)) //DebugMarch26th: added a '!' sign.
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("INVALID INPUT!", "def", "red");
		cout << endl;
		char ans;
		print_in_color(">Try again? (y/n): ", "def", "yellow");
		if (ans == 'n' || ans == 'N')
			return;
		print_in_color(">Try again: ", "def", "yellow");
		cin >> s;
	}


	///Getting all the books of the library from text file
	string fadd = "./text_folder2/booklistof_" + vlib.get_name() + "_" + vlib.get_address() + ".txt";
	ifstream curr_list(fadd);
	bookchain* booklistof_first = nullptr;
	bookchain* booklistof_last = nullptr;
	//bookchain* p = nullptr;
	int total = 0;
	while (curr_list.good())
	{
		book b;
		string s;
		curr_list >> s;
		b.set_ISBN(s);
		curr_list >> s;
		b.set_name(s);
		curr_list >> s;
		b.set_loaned(stoi(s));
		addtochain(b, booklistof_first, booklistof_last);
		total++;
	}
	curr_list.close();

	if (total == 0)
	{
		cout << endl;
		print_in_color("NO BOOKS IN THE LIBRARY!", "def", "red");
		return; //FUNCTION ENDS HERE
	}
	//possible bug
	bookchain* cleanbooklistof_first = nullptr;
	bookchain* cleanbooklistof_last = nullptr;
	int total_clean = 1;
	addtochain(booklistof_first->data, cleanbooklistof_first, cleanbooklistof_last);
	for (int i = 1; i < total; ++i)
	{
		for (int j = 0; j < total_clean; ++j)
		{
			bool same = true;
			for (int k = 0; k < 10; ++k)
			{

				if (nth_bookchain(j + 1, cleanbooklistof_first, cleanbooklistof_last)->data.get_ISBN()[k]
					!=
					nth_bookchain(i + 1, booklistof_first, booklistof_last)->data.get_ISBN()[k]
					)
				{
					same = false;
				}

			}
			if (same)
			{
				// replace kon va beppar biroon I think
				nth_bookchain(j + 1, cleanbooklistof_first, cleanbooklistof_last)->data =
					nth_bookchain(i + 1, booklistof_first, booklistof_last)->data;
				break;
			}
			else
			{
				addtochain(nth_bookchain(i + 1, booklistof_first, booklistof_last)->data,
					cleanbooklistof_first,
					cleanbooklistof_last);
				total_clean++;
			}
		}
	}



	bookchain* bookswithspecificgenre_first = nullptr;
	bookchain* bookswithspecificgenre_last = nullptr;
	int total_specific = 0;
	for (int i = 0; i < total_clean; ++i)
	{
		ifstream inbooks("./text_folder/books.txt");
		bool keepit = false;
		book curr_book;

		curr_book = nth_bookchain(i + 1, cleanbooklistof_first, cleanbooklistof_last)->data;
		while (inbooks.good())
		{
			book temp2(inbooks);
			//temp2 <> curr_book
			//if (is same and) !deleted and genre is what we need--> add
			
			/* ///***Code revisioned
			if (temp2.get_genre() == curr_book.get_genre())
			{
				addtochain(curr_book, bookswithspecificgenre_first, bookswithspecificgenre_last);
				total_specific++;
			}
			*/

			bool samesame = true;
			for (int j = 0; j < 10; ++j)
			{
				if (temp2.get_ISBN()[j] != curr_book.get_ISBN()[j])
					samesame = false;
			}
			if (samesame && temp2.get_deleted()==false && temp2.get_genre()==compare.get_genre())
			{
				keepit = true;
			}
			else
			{
				keepit = false;
			}
		}
		inbooks.close();
		if(keepit)
		{
			addtochain(curr_book, bookswithspecificgenre_first, bookswithspecificgenre_last);
			total_specific++;
		}
	}


	///Bubble Sort
	for (int i = 0; i < total_specific - 1; i++)

		// Last i elements are already in place    
		for (int j = 0; j < total_specific - i - 1; j++) //TODODONE erfan: strcmp baraye moghaayeseye author haa na genre haa //possible bug: '>' for string??
			if (nth_bookchain(j + 1, bookswithspecificgenre_first, bookswithspecificgenre_last)->data.get_author()
				>
				nth_bookchain(j + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last)->data.get_author()
				)
			{
				//swap(&arr[j], &arr[j + 1]);

				if (j != 0)
				{
					// f1 l r f2 ====> f1 r l f2

					bookchain* f1 = nth_bookchain(j, bookswithspecificgenre_first, bookswithspecificgenre_last);
					bookchain* l = nth_bookchain(j + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
					bookchain* r = nth_bookchain(j + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
					//bookchain* f2= nth_bookchain(j + 1 + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
					bookchain* f2 = r->next;


					f1->next = r;
					r->next = l;
					l->next = f2;
				}
				else
				{
					bookchain* l = nth_bookchain(j + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
					bookchain* r = nth_bookchain(j + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
					//bookchain* f2= nth_bookchain(j + 1 + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
					bookchain* f2 = r->next;

					r->next = l;
					l->next = f2;
				}

				/*
				bookchain* left = nth_bookchain(j+1, bookswithspecificgenre_first, bookswithspecificgenre_last);
				bookchain* right = nth_bookchain(j + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last);
				bookchain* next_temp = nth_bookchain(j + 1 + 1, bookswithspecificgenre_first, bookswithspecificgenre_last)->next;
				bookchain* temp3 = left;
				left = right;
				right = temp3;
				*/

			}

	//Printing the final result (bookswithspecificgenre)
	cout << endl << endl;
	for (int i = 0; i < total_specific - 1; i++)
	{
		book temp3 = nth_bookchain(i + 1, bookswithspecificgenre_first, bookswithspecificgenre_last)->data;
		
		print_in_color("Name: ", "def", "yellow");
		print_in_color(temp3.get_name(), "def", "aqua");
		cout << "\t";

		print_in_color("ISBN: ", "def", "yellow");
		for (int j = 0; j < 10; ++j)
		{
			char curr_char = temp3.get_ISBN()[j];
		print_in_color(to_string(curr_char), "def", "aqua");
		}
		cout << "\t";

		print_in_color("Author: ", "def", "yellow");
		print_in_color(temp3.get_author(), "def", "aqua");
		cout << "\t";
		cout << endl;
	}
}

void delete_a_library()
{
	cls();
	print_vasat("DELETE A LIBRARY!", "yellow", "red", console_columns_count());
	cout << endl << endl << endl;


	print_in_color("> Enter a valid library ADDRESS (existing/10chars/no whitespace): ", "def", "yellow");
	char vaddress[10];
	cin >> vaddress;

	ifstream inlibrary("./text_folder/libraries.txt");
	library obj;
	obj.set_deleted(true);
	while (inlibrary.good())
	{
		library temp(inlibrary);
		bool same = true;
		for (int i = 0; i < 10; i++)
		{
			if (temp.get_address()[i] != vaddress[i])
			{
				same = false;
			}
		}
		if (same)
		{
			obj = temp;
		}
	}
	inlibrary.close();

	if (obj.get_deleted() == true)
	{
		cout << endl;
		print_line_in_color(console_columns_count(), "red");
		cout << endl;
		print_in_color("Library doesn't exist!", "def", "red");
	}
	else
	{
		obj.set_deleted(true);
		///Adding to the libraries.txt
		ofstream libs("./text_folder/libraries.txt", ios::app);
		libs << endl << obj.get_name() << "\t" << obj.get_address() << "\t" << obj.get_deleted();
		libs.close();
	}

	cout << endl << endl << endl;
	print_vasat("Library successfully deleted!", "def", "green", console_columns_count());
	cout << endl;
	leaving_in(4, "def", "yellow");
}

void print_library_info()
{

}

void delete_a_book()
{
}

void print_book_info()
{
}

void assign_book_to_library(book thebook, library thelibrary) //TODO ali: check if it actually works...
{
	string fadd = "./text_folder2/booklistof_" + thelibrary.get_name() + "_" + thelibrary.get_address() + ".txt";
	ofstream new_file(fadd, ios::app);
	new_file << endl << thebook.get_ISBN() << "\t" << thebook.get_name() << "\t" << thebook.get_loaned();
	new_file.close();
}

void addtochain(book b, bookchain*& first, bookchain*& last)
{
	bookchain *temp = new bookchain;

	temp->data = b;
	temp->next = nullptr;
	if (first == nullptr)
	{
		first = temp;
		last = temp;
		temp = nullptr;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
}

void freethewholechain(bookchain*& first, bookchain*& last)
{
	bookchain* p;
	p = first;
	while (p->next != nullptr)
	{
		bookchain* del = p;
		p = p->next;
		delete del;
	}
	delete p;
}

bookchain* nth_bookchain(int n, bookchain*& first, bookchain*& last)
{
	bookchain* p = first;
	for (int i = 1; i < n; ++i)
	{
		if (p->next != nullptr)
			p = p->next;
	}
	return p;
}


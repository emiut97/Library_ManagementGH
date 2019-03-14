#include "standard_includes.h"
#include "console_functions_LEGACY.h"
#include "design_LEGACY.h"
#include "classes.h"
#include "functions.h"

int main()
{
	go_fullscreen();
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	print_line_in_color(columns, "yellow");
	cout << endl;
	print_vasat("Welcome to LIBRARY MANAGEMENT system!", "yellow", "red", columns);
	cout << endl;
	print_vasat("Developed by:", "def", "yellow", columns);
	cout << endl;
	print_vasat("1) Erfan Mazaheri 9734923", "def", "red", columns);
	cout << endl;
	print_vasat("2) Ali Seraj 9728343", "def", "red", columns);
	cout << endl << endl;
	delay(6000);
	//GOT_theme(); //TODO


	//		<<<ESSENTIALS>>>

	///^Controling exits
	SetConsoleCtrlHandler(CtrlHandler, TRUE);

	//library lib("mylib001", "1010101010");



	int option = 0;
	cls();
	welcome_page_manual();
	cin >> option;
	while (option != 99)
	{

		if (option == 1) //DONE
		{
			//Create a library
			cls();
			create_a_library();
		}

		if (option == 2) //TODO
		{
			//Add a book to a library
			cls();
			void add_a_book_to_a_library();
		}

		if (option == 3) //DONE
		{
			//Create a book
			cls();
			create_a_book();
		}

		if (option == 4) //TODO
		{
			//Loan/Return a book
			cls();
			loan_return_a_book();
		}

		if (option == 5) //TODO
		{
			//List by a specific genre
			cls();
			list_by_a_specific_genre();
		}

		if (option == 6) //DONE
		{
			//Delete a library
			cls();
			delete_a_library();
		}

		if (option == 7) //TODO
		{
			//Print library info
			cls();
			print_library_info();
		}

		if (option == 8) //TODO
		{
			//Delete a book
			cls();
			delete_a_book();
		}

		if (option == 9) //TODO
		{
			//Print book info
			cls();
			print_book_info();
		}

		

		cls();
		welcome_page_manual();
		cin >> option;
	}




}

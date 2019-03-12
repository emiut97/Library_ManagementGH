#include "standard_includes.h"
#include "console_functions_LEGACY.h"
#include "design_LEGACY.h"

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

	GOT_theme(); //TODO


	//		<<<ESSENTIALS>>>

	///^Controling exits
	SetConsoleCtrlHandler(CtrlHandler, TRUE);



	int option = 0;
	cls();
	welcome_page_manual();
	cin >> option;
	while (option != 99)
	{

		if (option == 1)
		{
			//Create a library
			cls();
		}

		if (option == 2)
		{
			//Add a book to a library
			cls();
		}

		if (option == 3)
		{
			//Create a book
			cls();
		}

		if (option == 4)
		{
			//Loan/Return a book
			cls();
		}

		if (option == 5)
		{
			//List by a specific genre
			cls();
		}

		if (option == 6)
		{
			//Delete a library
			cls();
		}

		if (option == 7)
		{
			//Print library info
			cls();
		}

		if (option == 8)
		{
			//Delete a book
			cls();
		}

		if (option == 9)
		{
			//Print book info
			cls();
		}

		

		cls();
		welcome_page_manual();
		cin >> option;
	}




}

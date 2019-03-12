#pragma once
//--------------------------

#include "standard_includes.h"
#include "console_functions_LEGACY.h"

//--------------------------
// Please declare here! (Define later :)) )
void welcome_page_manual();


//--------------------------
// Please define here!


void welcome_page_manual()
{
	cout << endl << endl;
	cout << "--------------------" << endl
		<< "1) Create a library" << endl
		<< "2) Add a book to a library" << endl
		<< "3) Create a book" << endl
		<< "4) Loan/Return a book" << endl
		<< "5) List by a specific genre" << endl
		<< "6) Delete a library" << endl
		<< "7) Print library info" << endl
		<< "8) Delete a book" << endl
		<< "9) Print book info" << endl << endl

		<< "99) exit" << endl << endl;
	print_in_color(">>>", "yellow", "black"); cout << " ";
}

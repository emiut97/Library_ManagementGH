#pragma once

#include "standard_includes.h"
#include "console_functions_LEGACY.h"

#include "classes.h"

//Haminja okay e baraye enum :|
enum genres  {
	Fantasy,
	Westerns,
	Romance,
	Thriller,
	Mystery,
	Detective_Story,
	Biography,
	Musical
};

class library
{
	string name = "~";
	char address[10] = {};
	book* head_book_ = NULL;
};

class book
{
	char ISBN[10] = {};
	char name[18] = {};
	string author = "~";
	genres genre;
	bool loaned = false;

public:
	book(ifstream& in);//TODO
};
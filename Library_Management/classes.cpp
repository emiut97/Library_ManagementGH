#pragma once

#include "standard_includes.h"
//#include "console_functions_LEGACY.h"

#include "classes.h"



/// LIBRARY>>>

void library::set_name(string new_name)
{
	name = new_name;
}

void library::set_name(const char* new_name)
{
	name = new_name;
}

string library::get_name() const
{
	return name;
}


void library::set_address(char new_address[])
{
	for (int i = 0; i < 10; ++i)
	{
		address[i] = new_address[i];
	}
}

const char* library::get_address() const //possible bug
{
	return address;
}


void library::set_deleted(bool new_deletion_state)
{
	deleted = new_deletion_state;
}

bool library::get_deleted() const
{
	return deleted;
}


library::library()
{
}

library::library(string new_name, char new_address[], bool deletion_state)
{
	name = new_name;
	set_address(new_address);
	set_deleted(deletion_state);
}

library::library(std::ifstream& in)
{
	in >> name >> address >> deleted; //possible bug: address is a char_array not a string
}



///   BOOK>>>

void book::set_ISBN(const char* new_ISBN)    //(char new_ISBN[])
{
	//TODO ali: agar kamtar az 10 ta bood chi?
	for (int i = 0; i < 10 && new_ISBN[i] != 'z' && new_ISBN[i] != '\0'; ++i)
	{
		ISBN[i] = new_ISBN[i];
	}
}

void book::set_ISBN(string new_ISBN)
{
	for (int i = 0; i < 10 && new_ISBN[i] != 'z' && new_ISBN[i] != '\0'; ++i) //possible bug: string as an array of chars
	{
		ISBN[i] = new_ISBN[i];
	}
}

const char* book::get_ISBN() const
{
	//TODO ali: check if it actually returns the whole daastaan
	return ISBN;
}


void book::set_name(char new_name[])
{
	//TODO ali: agar kamtar az 18 ta bood chi?
	for (int i = 0; i < 18 && new_name[i] != '~' && new_name[i] != '\0'; ++i)
	{
		name[i] = new_name[i];
	}
}

void book::set_name(string new_name)
{
	for (int i = 0; i < 18 && new_name[i] != '~' && new_name[i] != '\0'; ++i)//possible bug: string as an array of chars
	{
		name[i] = new_name[i];
	}
}

const char* book::get_name() const
{
	//TODO ali: check if it actually returns the whole daastaan
	return name;
}


void book::set_author(string new_author)
{
	author = new_author;
}

void book::set_author(const char* new_author)
{
	author = new_author;
}

string book::get_author() const
{
	return author;
}


void book::set_genre(genres new_genre)
{
	genre = new_genre;
}

bool book::set_genre(string new_genre)
{
	if (new_genre == "Fantasy")
	{
		genre = Fantasy;
		return true;
	}
	if (new_genre == "Westerns")
	{
		genre = Westerns;
		return true;
	}
	if (new_genre == "Romance")
	{
		genre = Romance;
		return true;
	}
	if (new_genre == "Thriller")
	{
		genre = Thriller;
		return true;
	}
	if (new_genre == "Mystery")
	{
		genre = Mystery;
		return true;
	}
	if (new_genre == "Detective_Story")
	{
		genre = Detective_Story;
		return true;
	}
	if (new_genre == "Biography")
	{
		genre = Biography;
		return true;
	}
	if (new_genre == "Musical")
	{
		genre = Musical;
		return true;
	}
	return false;
}

bool book::set_genre(int new_genre)
{
	switch (new_genre)
	{
		case 1:
			genre = Fantasy;
			break;
		case 2:
			genre = Westerns;
			break;
		case 3:
			genre = Romance;
			break;
		case 4:
			genre = Thriller;
			break;
		case 5:
			genre = Mystery;
			break;
		case 6:
			genre = Detective_Story;
			break;
		case 7:
			genre = Biography;
			break;
		case 8:
			genre = Musical;
			break;
		default:
			return false;
	}
	return true;
}

genres book::get_genre() const
{
	return genre;
}

int book::get_genre_int() const
{
	switch (genre)
	{
		case Fantasy:
			return 1;
		case Westerns:
			return 2;
		case Romance:
			return 3;
		case Thriller:
			return 4;
		case Mystery:
			return 5;
		case Detective_Story:
			return 6;
		case Biography:
			return 7;
		case Musical:
			return 8;
		default:
			return 0;
	}
}


void book::set_loaned(bool new_loan_state)
{
	loaned = new_loan_state;
}


bool book::get_loaned() const
{
	return loaned;
}


void book::set_deleted(bool new_deletion_state)
{
	deleted = new_deletion_state;
}

bool book::get_deleted() const
{
	return deleted;
}


book::book()
{
}

book::book(char vISBN[], char vname[], string vauthor, genres vgenre, bool vloaned, bool vdeleted)
{
	set_ISBN(vISBN); //possible bug ali: Check kon 2rost bashe OR maybe agar avaz koni set_ISBN o , in gir bede... 
	set_name(vname); //possible bug ali: mesle baalaayi
	set_author(vauthor);
	set_genre(vgenre);
	set_loaned(vloaned);
	set_deleted(vdeleted);
}

book::book(ifstream& in)
{
	//possible bug: different variable types... (does it auto cast?)
	string s;
	in >> ISBN >> name >> author >> s >> loaned >> deleted;
	set_genre(s); //possible bug ali: genre chetor save shode tooye file? cast az string be chi beshe s, ke bad az khoondan az file, dorost set beshe.
}

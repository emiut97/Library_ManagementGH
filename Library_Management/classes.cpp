#pragma once

#include "standard_includes.h"
//#include "console_functions_LEGACY.h"

#include "classes.h"

void library::set_name(string new_name)
{
	name = new_name;
}

void library::set_name(const char* new_name)
{
	name = new_name;
}

string library::get_name () const
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
	for (int i = 0; i < 10; ++i)
	{
		ISBN[i] = new_ISBN[i];
	}
}

const char* book::get_ISBN () const
{
	//TODO ali: check if it actually returns the whole daastaan
	return ISBN;
}

void book::set_name(char new_name[])
{
	//TODO ali: agar kamtar az 18 ta bood chi?
	for (int i = 0; i < 18; ++i)
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

genres book::get_genre() const
{
	return genre;
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
	//genre = s; //TODO ali: chetor cast beshe?
}

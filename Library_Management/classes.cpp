#pragma once

#include "standard_includes.h"
#include "console_functions_LEGACY.h"

#include "classes.h"

void library::set_name(string new_name)
{
	name = new_name;
}

void library::set_name(const char* new_name)
{
	name = new_name;
}

string library::get_name()
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

char* library::get_address() //possible bug
{
	return address;
}

library::library(string new_name, char new_address[])
{
	name = new_name;
	set_address(new_address);
	string fadd = "./text_folder2/booklistof_" + name + "_" + address + ".txt";
	ofstream new_file(fadd); //possible bug
	new_file.close();
}

library::library(std::ifstream& in)
{
	in >> name >> address >> deleted; //possible bug: address is a char_array not a string
}


void book::set_ISBN(char new_ISBN[])
{
	//???
}
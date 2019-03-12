#pragma once

//Haminja okay e baraye enum :|
enum genres {
	Fantasy,
	Westerns,
	Romance,
	Thriller,
	Mystery,
	Detective_Story,
	Biography,
	Musical
};


class library //TODO
{
	string name = "~";
	char address[10] = {};
	bool deleted = false;

public:
	void set_name(string new_name);
	void set_name(const char* new_name);
	string get_name();

	void set_address(char new_address[]);
	char* get_address();

public:
	library(string name, char address[]);//file ham besazim inja
	library(ifstream& in);

};

class book
{
	char ISBN[10] = {};
	char name[18] = {};
	string author = "~";
	genres genre;
	bool loaned = false;
	bool deleted = false;

public:
	void set_ISBN(char new_ISBN[]);
	char* get_ISBN();

	void set_name(char new_name[]);
	char* get_name();

	void set_author(string new_author);
	void set_author(const char* new_author);
	string get_author();

	void set_genre(genres new_genre);
	genres get_genre();

	void set_loaned(bool new_loan_state);
	bool get_loaned();

	void set_deleted(bool new_delete_state);
	bool get_deleted();

public:
	book(ifstream& in);//TODO


	
};
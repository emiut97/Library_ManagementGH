#pragma once

//Haminja okay e baraye enum :|
typedef enum genres {
	GNOTSET,
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
	string get_name () const;

	void set_address(char new_address[]);
	const char* get_address() const;

	void set_deleted(bool new_deletion_state);
	bool get_deleted() const;

public:
	library();
	library(string name, char address[], bool deletion_state);
	library(ifstream& in);

};

class book
{
	char ISBN[11] = { 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z'};
	char name[19] = { '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' , 
					'~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~' ,  '~'};
	string author = "~";
	genres genre = GNOTSET;
	bool loaned = false;
	bool deleted = false;

public:
	void set_ISBN(const char* new_ISBN);    //(char new_ISBN[])
	const char* get_ISBN() const;

	void set_name(char new_name[]);
	const char* get_name() const;

	void set_author(string new_author);
	void set_author(const char* new_author);
	string get_author() const;

	void set_genre(genres new_genre);
	bool set_genre(string new_genre);
	bool set_genre(int new_genre);
	genres get_genre() const;

	void set_loaned(bool new_loan_state);
	bool get_loaned() const;

	void set_deleted(bool new_deletion_state);
	bool get_deleted() const;

public:
	book();
	book(char vISBN[],  char vname[], string vauthor, genres vgenre, bool vloaned, bool vdeleted);
	book(ifstream& in);

};
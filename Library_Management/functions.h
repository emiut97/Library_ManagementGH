#pragma once
#include <locale>

///MAIN FUNCTIONS

// #1
void create_a_library();

// #2
void add_a_book_to_a_library();

// #3
void create_a_book();

// #4
void loan_return_a_book();

// #5
void list_by_a_specific_genre();

// #6
void delete_a_library();

// #7
void print_library_info();

// #8
void delete_a_book();

// #9
void print_book_info();




///OTHER FUNCTIONS

void assign_book_to_library(book thebook, library thelibrary);

void addtochain(book b, bookchain *&first, bookchain *&last);

void freethewholechain(bookchain *&first, bookchain *&last);

bookchain* nth_bookchain(int n, bookchain *&first, bookchain *&last);
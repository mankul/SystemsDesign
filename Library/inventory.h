#ifndef INVENTORY_H
#define INVENTORY_H
#include<map>
#include<vector>
#include"customer.h"
#include"books.h"



class Inventory{
    public:

        std::map<Book * , int> booksCount;
        std::map<Customer *, std::vector<BookCopy *> > issueBooks; 
        Inventory();
        ~Inventory();
        void submitBook(Customer * custID, BookCopy * bookCopy, time_t date);
        bool issueBook(Customer * custID, Book * book); // create a new book copy instance.
        int numberOfDays(std::string issueDate, std::string submitDate);
        int parseDate( std::string &, std::string);
};

#endif
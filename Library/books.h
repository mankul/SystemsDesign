#ifndef BOOKS_H
#define BOOKS_H
#include<string>
#include<ctime>

class Book
{   public:
    std::string bookName;
    int BookID;
    std::string subject;
    std::string title;
    std::string author;
    int fineCostPerDay;
    int allowedNumberOfDays;
    Book();
    ~Book();
};


class BookCopy{

    public:
        Book * book;
        int serialNumber;// serial number on copy
        time_t issueDate;
        BookCopy();
        ~BookCopy();
};


#endif
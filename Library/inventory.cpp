#include"inventory.h"
#include<iostream>



Inventory::Inventory(){
    std::cout<<"Inventory initiated"<<std::endl;
}

Inventory::~Inventory(){
    std::cout<<"Inventory Destructor"<<std::endl;
}


bool Inventory::issueBook(Customer * custID, Book * book){
    int numberOfBooksIdle = booksCount[book];
    if(numberOfBooksIdle == 0){
        return false;
    }   
    booksCount[book] -= 1;
    BookCopy * bookCopy = new BookCopy();
    bookCopy->book = book;
    bookCopy->issueDate = time(0);
}

void Inventory::submitBook(Customer * custID, BookCopy * bookCopy, time_t submitDate){
    Book * book = bookCopy->book;
    
    if(booksCount.find(book)!= booksCount.end()){
        booksCount[book]+=1;
    }

    if(issueBooks.find(custID) != issueBooks.end()){
        std::vector<BookCopy *> booksOfCust = issueBooks[custID];
        for(auto iterator = booksOfCust.begin(); iterator != booksOfCust.end(); iterator ++){
            if(*iterator == bookCopy){
                booksOfCust.erase(iterator);
            }
        }
        issueBooks[custID] = booksOfCust;
    }

    // calculate fine
    // if()

    double seconds = difftime(bookCopy->issueDate, submitDate);
    double days = seconds/(60 * 60 * 24);
    custID->fine+= (book->fineCostPerDay) * ((int)days + 1);
    bookCopy->~BookCopy();
}



int Inventory::numberOfDays(std::string issueDate, std::string submitDate){
    // assume date only in DD/MM/YYYY 
    std::string delimeter = "/";
    
    int issueDay = parseDate( issueDate, delimeter);
    int submitDay = parseDate( submitDate, delimeter);
    int issueMonth = parseDate( issueDate, delimeter);
    int submitMonth = parseDate( submitDate, delimeter);
    int issueYear = parseDate( issueDate, delimeter);
    int submitYear = parseDate( submitDate, delimeter);

}

int Inventory::parseDate(std::string & date, std::string delim){
    int position = date.find(delim);
    int value = stoi(date.substr(0, position));
    date.erase(position);
    return value;

}
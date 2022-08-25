#include"books.h"
#include<iostream>

Book::Book(){
    std::cout<<"Book Constructor"<<std::endl;
}

Book::~Book(){
    std::cout<<"Book Destructor"<<std::endl;
}


BookCopy::BookCopy(){
    std::cout<<"BookCopy Constructor"<<std::endl;
}

BookCopy::~BookCopy(){
    std::cout<<"BookCopy Destructor"<<std::endl;
}

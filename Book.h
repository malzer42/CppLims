/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Book.h
 * Author: Pierre Abraham Mulamba
 *
 * Created on 29 June 2020, 22 h 18
 */

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class Book {
public:
    // Constructors
    Book();
    Book(const std::string& quote, const std::string& title, unsigned short year, unsigned short minReaderAge, 
        unsigned int nPossess);
    Book(const Book& orig); // Copy constructor
    Book(Book&& orig)noexcept; // Move constructor
    
    virtual ~Book() = default; // Destructor
    
    Book& operator=(const Book& orig); // Copy Assignment operator
    Book& operator=(Book&& orig)noexcept; // Move Assignment operator
    
    // Getter methods
    const std::string& getQuote()const;
    const std::string& getTitle()const;
    unsigned short getYear()const;
    unsigned short getMinReaderAge()const;
    unsigned int getNPossess()const;
    unsigned int getNAvailables()const;
    
    // Setter methods
    void setQuote(const std::string& quote);
    void setTitle(const std::string& title);
    void setYear(unsigned short year);
    void setMinReaderAge(unsigned short minReaderAge);
    void setNPossess(unsigned int nPossess);
    void setNAvailables(unsigned int nAvailables);
    
    // Printing method
    void print()const;
    
private:
    std::string quote_;
    std::string title_;
    unsigned short year_;
    unsigned short minReaderAge_;
    unsigned int nPossess_;
    unsigned int nAvailables_;
};

#endif /* BOOK_H */


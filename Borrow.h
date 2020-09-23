/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Borrow.h
 * Author: Pierre Abraham Mulamba
 *
 * Created on 29 June 2020, 22 h 20
 */

#ifndef BORROW_H
#define BORROW_H
#include <string>
#include <memory>
#include "Subscriber.h"
#include "Book.h"

class Borrow {
public:
    // Constructors
    Borrow(std::shared_ptr<Subscriber>& sub, std::shared_ptr<Book>& book, const std::string& returnDate);
    
    // Copy and Move constructor
    Borrow(const Borrow& orig); // Copy constructor
    Borrow(Borrow&& orig)noexcept; // Move constructor
    
    // Copy and Move assignment operators
    Borrow& operator=(const Borrow& orig); // Copy assignment
    Borrow& operator=(Borrow&& orig)noexcept; // Move assignment
    
    virtual ~Borrow() = default; // Destructor
    
    // Getter methods
    std::shared_ptr<Subscriber> getSubscriber()const;
    std::shared_ptr<Book> getBook()const;
    const std::string& getReturnDate()const;
    
    // Setter methods
    void setSubscriber(std::shared_ptr<Subscriber>& subscriber);
    void setBook(std::shared_ptr<Book>& book);
    void setReturnDate(const std::string& returnDate);    
    
    // Printing method
    void print()const;
    
private:
    std::shared_ptr<Subscriber> subscriber_;
    std::shared_ptr<Book> book_;
    std::string returnDate_;    
};
    
#endif /* BORROW_H */


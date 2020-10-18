/**
 * File: Borrow.cpp
 * Author(s): Pierre Abraham Mulamba
 * Created (modified): 20200629, 22:20 (20200716, 19:57)
 * Description: Implementation of class Borrow
 */

#include"Borrow.h"

/**
 * Constructor with parameters
 * @param subscriber
 * @param book
 * @param returnDate
 */
Borrow::Borrow(std::shared_ptr<Subscriber>& sub, std::shared_ptr<Book>& book, const std::string& returnDate) : 
    subscriber_(sub), book_(book), returnDate_(returnDate)
{
    
}

// Getter methods

/**
 * Get the subscriber_ attribute
 * @return subscriber_ 
 */
std::shared_ptr<Subscriber> Borrow::getSubscriber()const{
    return subscriber_;
}

/**
 * Get the book_ attribute
 * @return book_
 */
std::shared_ptr<Book> Borrow::getBook() const{
    return book_;
}

/**
 * Get the returnDate_ attribute
 * @return returnDate_
 */
const std::string& Borrow::getReturnDate() const{
    return returnDate_;
}

// Setter methods

/**
 * Set subscriber_ attribute
 * @param subscriber
 */
void Borrow::setSubscriber(std::shared_ptr<Subscriber>& sub){
    subscriber_ = sub;
}

/**
 * Set book_ attribute
 * @param book
 */
void Borrow::setBook(std::shared_ptr<Book>& book){
    book_ = book;
}

/**
 * Set the returnDate_ attribute
 * @param returnDate
 */
void Borrow::setReturnDate(const std::string& returnDate){
    returnDate_ = returnDate;
}

// Copy and Move constructors
/**
 * Copy constructor
 * @param orig
 */
Borrow::Borrow(const Borrow& orig) : subscriber_(orig.getSubscriber()), book_(orig.getBook()), 
        returnDate_(orig.getReturnDate()){}

/**
 * Move constructor
 * @param orig
 */
Borrow::Borrow(Borrow&& orig)noexcept : subscriber_(nullptr), book_(nullptr), returnDate_(""){
    subscriber_ = orig.getSubscriber();
    book_ = orig.getBook();
    returnDate_ = orig.getReturnDate();
    
    std::shared_ptr<Subscriber> tmpSub = nullptr;      
    orig.setSubscriber(tmpSub);
    
    std::shared_ptr<Book> tmpBook = nullptr;
    orig.setBook(tmpBook);
    
    orig.setReturnDate("");
}

// Copy and Move assignments

/**
 * Copy assignment operator
 * @param orig
 * @return *this
 */
Borrow& Borrow::operator=(const Borrow& orig){
    if(this != &orig){
        subscriber_ = orig.getSubscriber();
        book_ = orig.getBook();
        returnDate_ = orig.getReturnDate();
    }
    return *this;
}

/**
 * Move assignment
 * @param orig
 * @return *this
 */
Borrow& Borrow::operator=(Borrow&& orig)noexcept{
     if(this != &orig){
         subscriber_ = nullptr;
         book_ = nullptr;
         returnDate_ = "";
         
         subscriber_ = orig.getSubscriber();
         book_ = orig.getBook();
         returnDate_ = orig.getReturnDate();
         
         std::shared_ptr<Subscriber> tmpSub = nullptr;
         orig.setSubscriber(tmpSub);
         
         std::shared_ptr<Book> tmpBook = nullptr;
         orig.setBook(tmpBook);
         orig.setReturnDate("");
     }
     return *this;
}

/**
 * Printing method
 */
void Borrow::print()const{
    std::cout << " #" << getSubscriber()->getIdNumber() 
            << ". " << getBook()->getQuote() 
            << ". " << getReturnDate() << ".\n";
    
}




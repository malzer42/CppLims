/** 
 * File:   Book.cpp
 * Author: Pierre Abraham Mulamba
 * 
 * Created on 29 June 2020, 22 h 18
 */

#include "Book.h"

/**
 */
Book::Book() {
    quote_ = "quote";
    title_ = "title";
    year_ = 0;
    minReaderAge_ = 0;
    nPossess_ = 0;
    //nAvailables_ = nPossess_;
}

/**
 * Constructor with parameters
 * @param quote
 * @param title
 * @param year
 * @param minReaderAge
 * @param nPossess
 */
Book::Book(const std::string& quote, const std::string& title, unsigned short year, unsigned short minReaderAge, 
        unsigned int nPossess) : quote_(std::move(quote)), title_(std::move(title)), 
        year_(year), minReaderAge_(minReaderAge), 
        nPossess_(nPossess)
{
    setNAvailables(getNPossess());
    //nAvailables_ = 0;
    //nAvailables_ = getNPossess(); //nPossess_;    
}

// Getter methods
/**
 * Get the quote_ attribute
 * @return quote_
 */
const std::string& Book::getQuote()const{
    return quote_;
}

/**
 * Get the title_ attribute
 * @return title_
 */
const std::string& Book::getTitle() const{
    return title_;
}

/**
 * Get the year_ attribute
 * @return year_
 */
unsigned short Book::getYear() const{
    return year_;
}

/**
 * Get the minReaderAge_ attribute
 * @return minReaderAge_
 */
unsigned short Book::getMinReaderAge() const{
    return minReaderAge_;
}

/**
 * Get the nPossess_ attribute
 * @return nPossess_
 */
unsigned int Book::getNPossess() const{
    return nPossess_;
}

/**
 * Get the nAvailables_ attribute
 * @return nAvailables_
 */
unsigned int Book::getNAvailables() const{
    return nAvailables_;
}

// Setter methods
/**
 * Set the quote_ attribute
 * @param quote
 */
void Book::setQuote(const std::string& quote){
    quote_ = quote;
}

/**
 * Set the title_ attribute
 * @param title
 */
void Book::setTitle(const std::string& title){
    title_ = title;
}

/**
 * Set the year_ attribute
 * @param year
 */
void Book::setYear(unsigned short year){
    year_ = year;
}

/**
 * Set the minReaderAge_ attribute
 * @param minReaderAge
 */
void Book::setMinReaderAge(unsigned short minReaderAge){
    minReaderAge_ = minReaderAge;
}

/**
 * Set the nPossess_ attribute
 * @param nPossess
 */
void Book::setNPossess(unsigned int nPossess){
    nPossess_ = nPossess;
}

/**
 * Set the nAvailables_ attribute
 * @param nAvailables
 */
void Book::setNAvailables(unsigned int nAvailables){
    nAvailables_ = nAvailables;
}



// Copy and Move constructors
/**
 * Copy constructor
 * Assign the orig attributes to the instance attributes
 * @param orig
 */
Book::Book(const Book& orig) : quote_(std::move(orig.getQuote())), title_(std::move(orig.getTitle())), 
        year_(orig.getYear()), minReaderAge_(orig.getMinReaderAge()), nPossess_(orig.getNPossess())
{
}

/**
 * Move constructor
 * First, initialize the instance attributes
 * Second, assign orig attributes to the instance attributes
 * Third, set the orig attributes
 * @param orig
 */
Book::Book(Book&& orig)noexcept : quote_(""), title_(""), year_(0), minReaderAge_(0), nPossess_(0)
{
    quote_ = orig.getQuote();
    title_ = orig.getTitle();
    year_ = orig.getYear();
    minReaderAge_ = orig.getMinReaderAge();
    nPossess_ = orig.getNPossess();
    //nAvailables_ = orig.getNAvailables();
    
    orig.setQuote("");
    orig.setTitle("");
    orig.setYear(0);
    orig.setMinReaderAge(0);
    orig.setNPossess(0);
}

// Copy and Move assignment operators

/**
 * Copy assignment operator
 * Add a conditional statement that performs no operation if you try to assign the object to itself.
 * @param orig
 * @return *this 
 */
Book& Book::operator=(const Book& orig){
    if(this != &orig){
        quote_ = orig.getQuote();
        title_ = orig.getTitle();
        year_ = orig.getYear();
        minReaderAge_ = orig.getMinReaderAge();
        nPossess_ = orig.getNPossess();
        nAvailables_ = orig.getNAvailables();
    }
    return *this;    
}


/**
 * Move assignment operator
 * First, add a conditional statement that performs no operation if you try to assign the object to itself.
 * Second, in the conditional statement, free any resources (such as memory) from the object that is being assigned to.
 * Third, assign from orig attributes to the instance attributes
 * Fourth, in the conditional statement, free any resources (such as memory) from orig
 * @param orig
 * @return *this
 */
Book& Book::operator=(Book&& orig)noexcept{
    
    
    if(this != &orig){ // 1. Conditional statement that performs no operation if your try to assign the ob itself.
        // 2. Free any resources from the object that is being assigned to 
        quote_ = "";
        title_ = "";
        year_ = 0;
        minReaderAge_ = 0;
        nPossess_ = 0;
        nAvailables_ = 0;
        
        // 3. Assign from the orig attributes to the instance attributes        
        quote_ = orig.getQuote();
        title_ = orig.getTitle();
        year_ = orig.getYear();
        minReaderAge_ = orig.getMinReaderAge();
        nPossess_ = orig.getNPossess();
        nAvailables_ = orig.getNAvailables();
        
        // 4. Free any resources from the orig
        orig.setQuote("");
        orig.setTitle("");
        orig.setYear(0);
        orig.setMinReaderAge(0);
        orig.setNPossess(0);
        orig.setNAvailables(0);
    }
    
    return *this;
}

void Book::print()const{
    std::cout << getQuote() <<". " << getTitle() <<". " << getYear()<<". " << getMinReaderAge() << " y.o.\n";
    //std::cout << "n_p: " << getNPossess() << '\n';
    //std::cout << "n_a: " << getNAvailables() << '\n';
}


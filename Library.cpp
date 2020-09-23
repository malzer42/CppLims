/** 
 * File:Library.cpp
 * Author: Pierre Abraham Mulamba
 * Created (modified):  20200629, 22:21 (20200714, 22:11)
 */

#include "Library.h"

/**
 * Default constructor
 */
Library::Library(){
    try{
        std::cout << "\nConstructor of a Library\n";
        if(!subs_.empty()){
            for(unsigned int i =0; i < subs_.size(); i++){
                subs_[i] = nullptr;
            }
        }
        else{
            std::cout << "No subscriber in the list of subscribers\n";
        }
        
        if(!books_.empty()){
            for(unsigned int i = 0; i < books_.size(); i++){
                books_[i] = nullptr;
            }            
        }
        else{
            std::cout << "No book in the list of books\n";            
        }
        
        if(!borrows_.empty()){
            for(unsigned int i = 0; i < borrows_.size(); i++){
                borrows_[i] = nullptr;
            }             
        }
        else{
            std::cout << "No borrow in the list of borrows\n";            
        }        
    }
    catch(...){
        std::cerr << "Ctor error \n";
    }
}

/**
 * Copy constructor
 * @param orig
 */
Library::Library(const Library& orig) : subs_(orig.getSubs().begin(), orig.getSubs().end()), 
        books_(orig.getBooks().begin(), orig.getBooks().end()), 
        borrows_(orig.getBorrows().begin(), orig.getBorrows().end())
{
}

/**
 * Move constructor
 * @param orig
 * @return 
 */
Library::Library(Library&& orig) noexcept 
{
    subs_ = orig.getSubs(); 
    books_ = orig.getBooks(); 
    borrows_ = orig.getBorrows(); 
    
    orig.getSubs().clear();
    orig.getBooks().clear();
    orig.getBorrows().clear();
}


/**
 * Copy assignment operator
 * @param orig
 * @return *this
 */
Library& Library::operator=(const Library &orig){
    if(this != &orig){
        subs_ = orig.getSubs();
        books_ = orig.getBooks();
        borrows_ = orig.getBorrows();
    }
    return *this;    
}

/**
 * Move assignment operator
 * @param orig
 * @return 
 */
Library& Library::operator=(Library&& orig)noexcept{
    if(this != &orig){
        
        subs_.clear();
        books_.clear();
        borrows_.clear();
        
        subs_ = orig.getSubs();
        books_ = orig.getBooks();
        borrows_ = orig.getBorrows();
        
        orig.getSubs().clear();
        orig.getBooks().clear();
        orig.getBorrows().clear();
    }
    return *this;   
}

Library::~Library() {
}

// Processing subscribers in the library

/**
 * Adding an instance of Subscriber to the list of subs_
 * @param subscriber
 */
void Library::addSubscriber(std::shared_ptr<Subscriber>& sub){
    subs_.push_back(sub);
}

/**
 * Remove an instance of Subscriber to the list of subs_
 * @param id
 */
void Library::removeSubscriber(const std::string& id){
    for(unsigned short i = 0; i < subs_.size(); i++){
        if(subs_[i]->getIdNumber().compare(id) == 0){
            subs_[i] = subs_[subs_.size() - 1];
            subs_.pop_back();
            break;
        }        
    }
}

//void sortSubscriber(unsigned int option);
//void swapSubscriber(Subscriber &sub1, Subscriber &sub2);

// Processing books in the library

/**
 * Adding an instance of Book to the Library
 * @param book
 */
void Library::addBook(std::shared_ptr<Book>& book){
    books_.push_back(book);
}

/**
 * Removing a book instance from the Library
 * @param quote
 */
void Library::removeBook(const std::string& quote){
    for(unsigned short i = 0; i < books_.size() ; i++){
        if(books_[i]->getQuote().compare(quote) == 0){
            books_[i] = books_[books_.size() - 1];
            books_.pop_back();
            break;
        }
    }
}

// Processing borrowers in the library
/**
 * Adding a Borrow instance in the Library
 * @param borrow
 */
void Library::addBorrow(std::shared_ptr<Borrow>& borrow){
    borrows_.push_back(borrow);
}

/**
 * Removing a Borrow instance in the Library
 * @param idNumber
 * @param quote
 */
void Library::removeBorrow(std::shared_ptr<Borrow>& borrow){
    for(unsigned short i = 0; i < borrows_.size() ; i++){
        if(borrows_[i]->getSubscriber()->getIdNumber() == borrow->getSubscriber()->getIdNumber() && 
                borrows_[i]->getBook()->getQuote() == borrow->getBook()->getQuote() ){
            borrows_[i] = borrows_[borrows_.size() - 1];
            borrows_.pop_back();
            //borrows_[i]->getBook()->setNAvailables(borrows_[i]->getBook()->getNAvailables() + 1);
            break;
        }
    }    
}


// void sortBook(unsigned int option);
// void swapBook(Book &book1, Book &book2);

// Searching, borrowing, returning, displaying methods

/**
 * Searching instances of Book by title
 * @param title
 */
void Library::searchTitle(const std::string &title){
    bool isPresent = false;
    for(unsigned short i = 0; i < books_.size(); i++){
        if (books_[i]->getTitle().find(title) != std::string::npos){
            books_[i]->print();
            isPresent = true;
        }
    }
    if(!isPresent){
        std::cout << "!!! No book with the Title: " << title << " found in the library!!!\n";
    }
}


/**
 * Searching instances of Book by quote
 * @param book_quote
 */
void Library::searchQuote(const std::string &quote){
    const int MAX_BOOK = 1000;
    std::cout << "Searching by quote...: " << quote << '\n';
    if (books_.size() <= 0 || MAX_BOOK < books_.size()) {
        std::logic_error description("Range_Error-- Could Not run the searchQuote");
        throw;
    }
    else {
        std::regex pattern(quote);
        bool isFound = false;
        for (unsigned short i = 0; i < books_.size(); i++) {
            if (std::regex_search(books_[i]->getQuote(), pattern)) {
                //std::cout << "nBooks_:" << books_.size() <<". i: " << i <<'\n';
                isFound = true;
                books_[i]->print();
            }
        }
        if (!isFound) {
            std::cout << "!!! Could not find a book with Quote: " << quote << "!!!\n";
        }
    }    
    //std::cout << "Leaving the search of quote\n";
}


/**
 * Borrowing a book based on some conditions 
 * Check if is possible for a Subscriber to borrow a specific book
 * If yes, then a new borrow instance is added to the list of borrowers
 * The following conditions are to be met for a Subscriber to borrow a book:
 * 1. The book is available
 * 2. The subscriber meets the age criterial -- the subscriber age >= book min reader age
 * 3. The subscriber did not already borrow the book
 * 4. The subscriber did exceed the maximum number of books allowed to borrow -- 2 by subscriber
 * The method return a Boolean value to indicate a successful or failure of a book
 * @param idNumber
 * @param quote
 * @param returnDate
 * @return 
 */
bool Library::borrowBookBySubscriber(const std::string &idNumber, const std::string &quote, const std::string& returnDate){
    //std::cout << "\nProcessing borrowBook...: \n"
    //        << "nSubs_: " << subs_.size() << ", nBooks_ " << books_.size() << ", nBorrows_: " << borrows_.size() << '\n';
    const unsigned short MAX_BORROW_ALLOWED = 2;
    bool isSuccessful = false;
    bool isBookAvailable = false;
    bool isSubOldToReadTheBook = false;
    bool condition_one_and_two = false;
    
    unsigned short iSub = 0;
    unsigned short iBook = 0;
    
    if(borrows_.empty()){
        //std::cout << "Checking condition 1 (Book available). nBorrows_: " << borrows_.size() << '\n';
        // Check condition 1.
        for(unsigned short i = 0; i < books_.size(); i++){
            if(books_[i]->getQuote() == quote){
                //std::cout << "Number of books available: " << books_[i]->getNAvailables() << '\n';
                isBookAvailable = ((books_[i]->getNAvailables() > 0) ? true : isBookAvailable);
                iBook = i;
                break;
            }
        }
        
        //std::cout << "iBook " << iBook << ", isBookAvailable: " << isBookAvailable << '\n';
        
        // Check condition 2.
        //std::cout << "Checking condition 2 (Age). nBorrows_: " << borrows_.size() << '\n';
        for(unsigned short j = 0; j < subs_.size(); j++){
            if(subs_[j]->getIdNumber() == idNumber){
                //std::cout << "Subscriber age: " << subs_[j]->getAge() << '\n';
                //std::cout << "Book reader age: " << books_[iBook]->getMinReaderAge() << '\n';
                        
                isSubOldToReadTheBook = ((subs_[j]->getAge() >= books_[iBook]->getMinReaderAge()) ? true : false );
                iSub = j;
                break;
            }
        }
        
        //std::cout << "iSub: " << iSub << ", isSubOldToReadTheBook: " << isSubOldToReadTheBook << '\n';
        
        // Condition 1 and 2  
        condition_one_and_two = isBookAvailable && isSubOldToReadTheBook;
        
        //std::cout << "Conditions 1 (Book Available) and 2 (Age). condition_one_and_two : " << condition_one_and_two << '\n';
        
        /**
         * nBorrows_ == 0
         * We do not check condition 3
         * We do not check condition 4
         */
        if(condition_one_and_two){
            //Borrow borrow(subs_[iSub], books_[iBook], returnDate);
            //addBorrow(borrow);
            std::shared_ptr<Borrow> borrow = std::make_unique<Borrow>(subs_[iSub], books_[iBook], returnDate);
            
            borrows_.push_back(borrow); // = &*borrow; //Borrow(subs_[iSub], books_[iBook], returnDate);
            borrows_[borrows_.size() - 1 ]->print();
            books_[iBook]->setNAvailables( books_[iBook]->getNAvailables() - 1 );
            isSuccessful = true;
        }
    }
    else if(borrows_.size() > 0){
        //std::cout << "Checking condition 3 (has already borrowed the Book). nBorrows_: " << borrows_.size() << '\n';
        unsigned short counterSub = 0;
        bool hasBorrowedTheBook = false;
        
        for(unsigned short k; k < borrows_.size(); k++){
            if(borrows_[k]->getSubscriber()->getIdNumber()== idNumber){
                counterSub++;
                hasBorrowedTheBook = ( ( borrows_[k]->getBook()->getQuote() == quote ) ? true : false);
            }
        }
        
        //std::cout << "counterSub: " << counterSub << ", hasBorrowedTheBook: " << hasBorrowedTheBook << '\n';
        
        // Check condition 1.
        for(unsigned short i = 0; i < books_.size(); i++){
            if(books_[i]->getQuote() == quote){
                isBookAvailable = ((books_[i]->getNAvailables() > 0) ? true : isBookAvailable);
                iBook = i;
                break;
            }
        }
        
        // Check condition 2.
        for(unsigned short j = 0; j < subs_.size(); j++){
            if(subs_[j]->getIdNumber() == idNumber){
                isSubOldToReadTheBook = ((subs_[j]->getAge() >= books_[iBook]->getMinReaderAge()) ? true : false );
                iSub = j;
                break;
            }
        }
        
        // Condition 1 and 2  
        condition_one_and_two = isBookAvailable && isSubOldToReadTheBook;
        
        //std::cout << "Conditions 1 (Book Available) and 2 (Age). condition_one_and_two : " << condition_one_and_two << '\n';
        
        if((!hasBorrowedTheBook && counterSub < MAX_BORROW_ALLOWED) && condition_one_and_two ){
            //Borrow borrow(subs_[iSub], books_[iBook], returnDate);
            //addBorrow(borrow);
            std::shared_ptr<Borrow> borrow = std::make_unique<Borrow>(subs_[iSub], books_[iBook], returnDate);
            borrows_.push_back(borrow); //[nBorrows_++] = &*borrow; //Borrow(subs_[iSub], books_[iBook], returnDate);
            books_[iBook]->setNAvailables( books_[iBook]->getNAvailables() - 1 );
            isSuccessful = true;
        }       
        
    }
    else{
        isSuccessful = false;        
    }
    return isSuccessful;
}

/**
 * Return method
 * If the subscriber has borrowed the book, the borrow record is deleted 
 * from the list borrows_
 * Return a Boolean value for a successful or failed return
 * Return a borrowed book by the Subscriber in the Library
 * @param subscriber_id
 * @param book_quote
 * @return isBookReturned
 */
bool Library::returnBook(const std::string &idNumber, const std::string &quote){
    bool isBookReturned = false;
    for(unsigned short i = 0; i < borrows_.size(); i++){
        if(borrows_[i]->getSubscriber()->getIdNumber() == idNumber && borrows_[i]->getBook()->getQuote() == quote ){
            removeBorrow(borrows_[i]);
            //borrows_[i] = borrows_[nBorrows_ -1];
            //nBorrows_--;
            //borrows_[i]->getBook()->setNAvailables(borrows_[i]->getBook()->getNAvailables() + 1);
            isBookReturned = true;
            break;
        }
    }
    
    for(unsigned short i = 0; i < books_.size(); i++){
        if (books_[i]->getQuote() == quote){
            books_[i]->setNAvailables(books_[i]->getNAvailables() + 1);
            break;
        }
    }
    
    return isBookReturned;
}

/**
 * InfoSubscriber method
 * @param subscriber_id
 */
void Library::infoSubscriber(const std::string &idNumber) const{
    for (unsigned short i = 0; i < borrows_.size(); i++) {
        if (borrows_[i]->getSubscriber()->getIdNumber() == idNumber) {
            borrows_[i]->getSubscriber()->print();
            break;
        }
    }
    
    for (unsigned short i = 0; i < borrows_.size(); i++) {
        if (borrows_[i]->getSubscriber()->getIdNumber() == idNumber) {
            borrows_[i]->print();
        }
    }
}

//void swapBorrow(Borrow &borrow1, Borrow &borrow2);

/**
 * Printing methods
 */
void Library::print()const{
    if(!subs_.empty()){
        std::cout << "\n\tPrinting the Subscribers of the Library with a display function as a predicate ...\n";
        std::for_each(subs_.begin(), subs_.end(), display);
        //for(auto& sub : subs_) sub->print();
    }
    
    if(!books_.empty()){
        std::cout << "\n\tPrinting the Books of the Library ...\n";
        for(auto& book : books_) book->print(); 
    }
    
    if(!borrows_.empty()){
        std::cout << "\n\tPrinting the Borrowers of the Library ...\n";    
        for(auto& borrow : borrows_) borrow->print();
    }
}

void display(std::shared_ptr<Subscriber> ps)
{
    ps->print();
}


std::vector<std::shared_ptr<Subscriber>> Library::getSubs()const{
    return subs_;
}
std::vector<std::shared_ptr<Book>> Library::getBooks()const{
    return books_;
}
std::vector<std::shared_ptr<Borrow>> Library::getBorrows()const{
    return borrows_;
}
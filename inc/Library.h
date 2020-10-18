/**
 * File: Library.h
 * Author: Pierre Abraham Mulamba
 * Created (modified):  20200629, 22:21
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdexcept>
#include <exception>
#include <memory> // std::shared_ptr, std::make_unique<Type>
#include <regex> // std::regex, std::regex_match, std::regex_search, std::regex_replace
#include <vector>
#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"

class Library {
public:

  Library(); // Ctor
  Library(const Library& orig);
  Library(Library&& orig) noexcept;
  Library& operator=(const Library &orig);
  Library& operator=(Library&& orig)noexcept;
  virtual ~Library(); // Dtor

  class BadLibrary : public std::exception {
  public:
    const std::string exceptionMsg = {"BadLibraryError: Unable to process item in the library\n"};
  };

  // Getter methods
  std::vector<std::shared_ptr<Subscriber>> getSubs()const;
  std::vector<std::shared_ptr<Book>> getBooks()const;
  std::vector<std::shared_ptr<Borrow>> getBorrows()const;

  // Setter methods
  void setSubs(const std::vector<std::shared_ptr<Subscriber>>& subs);
  void setBooks(const std::vector<std::shared_ptr<Book>>& books);
  void setBorrows(const std::vector<std::shared_ptr<Borrow>> borrows);

  // Processing subscribers in the library
  void addSubscriber(std::shared_ptr<Subscriber>& subscriber);
  void delSubscriber(const std::string& id);
  void sortSubscriber(unsigned int option);
  void swapSubscriber(Subscriber &sub1, Subscriber &sub2);

  // Processing books in the library
  void addBook(std::shared_ptr<Book>& book);
  void delBook(const std::string& quote);
  void sortBook(unsigned int option);
  void swapBook(Book &book1, Book &book2);

  // Searching, borrowing, returning, displaying methods
  void searchTitle(const std::string &str);
  void searchQuote(const std::string &book_quote);
  bool borrowBookBySubscriber(const std::string &subscriber_id, const std::string &book_quote, const std::string& returnDate);
    bool returnBook(const std::string &subscriber_id, const std::string &book_quote);
    void infoSubscriber(const std::string &subscriber_id) const;
    void swapBorrow(Borrow &borrow1, Borrow &borrow2);
    void print()const;

private:
  std::vector<std::shared_ptr<Subscriber>> subs_;
  std::vector<std::shared_ptr<Book>> books_;
  std::vector<std::shared_ptr<Borrow>> borrows_;

  /**
   * Adding and instance of Borrow to the list of Borrowers
   * @param borrow
   */
  void addBorrow(std::shared_ptr<Borrow>& borrow);
  /**
   * Removing an instance of Borrow to the list of Borrowers
   * @param borrow
   */
  void delBorrow(std::shared_ptr<Borrow>& borrow);
};

void display(std::shared_ptr<Subscriber> ps);

#endif /* LIBRARY_H */


/**
 * File:   main.cpp
 * Author: Pierre Abraham Mulamba
 * Created (modified) on : 20200629, 19:28 (20241014, 15:47)
 * Description: Supreme Commander
 */

#include <iostream>
#include <chrono>
#include <memory>

#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"
#include "Library.h"
#include "Title.h"


/*
 * Supreme Commander
 */
int main(int argc, char* argv[])
{
  try{
    //const std::string version = "20180625 LTS";
    //const std::string program = argv[0];
    //std::string program1(program, 89, program.size());
    //Title title(program1, version);

    std::cout << "\n\t\tLIBRARY MANAGEMENT INVENTORY SYSTEM.\n"
              << "\t\t-----INTEGRATION TEST PROGRAM.-------\n";

    clock_t begin = clock();

    // Creation of instances of Subscriber
    auto sub0 = std::make_shared<Subscriber>("1111", "Jean", "Baptiste", 20, "89756");
    auto sub1 = std::make_shared<Subscriber>("1839456", "John", "Doe", 23, "12345");
    auto sub2 = std::make_shared<Subscriber>("1630236", "Nicolas", "Gagnon", 8, "67891");
    auto sub3 = std::make_shared<Subscriber>("1268348", "Martin", "Tremblay", 18, "10112");

    std::cout << "\n\t\tPRINTING SUBSCRIBER INSTANCES\n";
    sub0->print();
    sub1->print();
    sub2->print();
    sub3->print();

    // Subscriber sub("1234", "sub", "bus", 100, "98765");
    // std::cin >> sub;
    // std::cout << sub;

    // Creation of Books instances
    auto book7 = std::make_shared<Book>("HB514", "Big D++", 2010, 9, 4); // ("GA403", "Big C++", 2009, 8, 3);
    auto book1 = std::make_shared<Book>("GA403", "Big C++", 2009, 8, 3); // ("GA403", "Big C++", 2009, 8, 3)
    auto book2 = std::make_shared<Book>("QA203", "Multiple variables Calculus part 1", 2011, 3, 2);
    auto book3 = std::make_shared<Book>("QA204", "Multiple variables Calculus part 2", 2011, 3, 2);
    auto book4 = std::make_shared<Book>("AC409", "Le chateau d'Ortrante", 1764, 16, 1);
    auto book5 = std::make_shared<Book>("BD302", "Harry Potter and the Azkaban prisoner", 1999, 3, 1);
    auto book6 = std::make_shared<Book> ("CE413", "Ibssz Qpuufs et le prisionier c'balbcbo", 2000, 4, 7);

    std::cout << "\n\t\tPRINTING BOOK INSTANCES\n";


    book1->print();
    book2->print();
    book3->print();
    book4->print();
    book5->print();
    book6->print();
    book7->print();

    // Creation of a Library instance
    Library library;
    library.addSubscriber(sub1);
    library.addSubscriber(sub2);
    library.addSubscriber(sub3);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);
    library.addBook(book6);
    library.addBook(book7);

    std::cout << "\n\t\tPRINTING THE CONTENT OF THE LIBRARY";
    library.print();

    std::cout << "\n/*******************************************************************/\n";
    std::cout << "/*                      BEGINNING OF TESTS                         */\n";
    std::cout << "/* Remaining modification are at the bottom of main function    .  */\n";
    std::cout << "/*******************************************************************/\n";


    std::cout << "\n\t\tSEARCHING BOOKS BY TITLE\n";
    std::cout << "Search for a title containing: Calcul\n";
    library.searchTitle("Calcul");

    std::cout << "\nSearch for a title containing: Small\n";
    library.searchTitle("Small");

    std::cout << "\nSearch for a title containing: Big\n";
    library.searchTitle("Big");

    std::cout << "\n\t\tSEARCHING BOOKS BY QUOTE\n";
    // Search by quote
    std::cout << "\nSearch for a quote containing: AC409\n";
    library.searchQuote("AC409");
    std::cout << "\nSearch for a quote containing: BD302\n";
    library.searchQuote("BD302");
    std::cout << "\nSearch for a quote containing: QA204\n";
    library.searchQuote("QA204");
    std::cout << "\nSearch for a quote containing: QA203\n";
    library.searchQuote("QA203");
    std::cout << "\nSearch for a quote containing: AC209\n";
    library.searchQuote("AC209");

    std::cout <<"\n\t\tTESTING THE BORROWING\n\n";
    std::cout << "\n// Should fail because Nicolas is too young! AC409 <--> 1630236\n";
    if (library.borrowBookBySubscriber("1630236", "AC409", "160204"))
      {
        std::cout << "AC409 borrowed by 1630236\n";
      }
    else{
      std::cout << "(Fail)!!!BORROWING OF AC409 by 1630236 failed because the Subscriber Nicolas is too young!!!\n";
    }

    std::cout << "\n// Should work. BD302 borrowed by 1630236\n";
    if (library.borrowBookBySubscriber("1630236", "BD302", "160204"))
      {
        std::cout << "(Pass)BD302 borrowed by 1630236\n";
      }
    else{
      std::cout << "!!!BORROWING BD302 by 1630236 failed!!!\n";
    }

    std::cout << "\n// Should not work because the book is not available anymore\n";
    if (library.borrowBookBySubscriber("1839456", "BD302", "160204"))
      {
        std::cout << "BD302 borrowed by 1839456\n";
      }
    else{
      std::cout << "(Fail)!!!BORROWING BD302 by 1839456 failed because the book is not Available!!!\n";
    }

    std::cout << "\n// Should not work because the subscriber has the book\n";
    if (library.borrowBookBySubscriber("1630236", "BD302", "160204"))
      {
        std::cout << "BD302 borrowed by 1630236\n";
      }
    else{
      std::cout << "(Fail)!!!BORROWING BD302 by 1630236 failed because the Subscriber has the book!!!\n";
    }

    std::cout << "\n// Should work\n";
    if (library.borrowBookBySubscriber("1630236", "QA204", "160204"))
      {
        std::cout << "(Pass)QA204 borrowed by 1630236\n";
      }
    else{
      std::cout << "!!!BORROWING QA204 by 1630236 failed!!!\n";
    }

    std::cout << "\n// Should not work because the subscriber has reached the limit of books to borrow\n";
    if (library.borrowBookBySubscriber("1630236", "QA203", "160204"))
      {
        std::cout << "QA203 borrowed by 1630236\n";
      }
    else {
      std::cout << "(Fail)!!!BORROWING QA203 by 1630236 failed because the limit is exceeded!!!\n";
    }

    // Info of a subscriber before returning a book
    std::cout << "\n\t\tINFO OF A SUBSCRIBER BEFORE RETURNING A BOOK.\n";
    library.infoSubscriber("1630236");

    std::cout << "\n\t\tTESTS ON BOOKS RETURN.\n";

    std::cout << "// should work\n";
    if (library.returnBook("1630236", "QA204"))
      {
        std::cout << "(Pass)QA204 return by 1630236\n";
      }
    else{
      std::cout << "!!!Returning of BD302 by 1630236 Failed!!!\n";
    }

    std::cout << "// Should not work because the subscriber never borrowed a book\n";
    if (library.returnBook("1839456", "QA203"))
      {
        std::cout << "QA203 return by 1839456\n";
      }
    else{
      std::cout << "(Fail)!!!Returning failed because the Subscriber 1839456 never borrowed a book!!!\n";
    }

    // Info of a Subscriber after returning a book
    std::cout << "\n\t\tINFO OF A SUBSCRIBER AFTER RETURNING A BOOK.\n";
    library.infoSubscriber("1630236");

    library.print();

    std::cout << "\n/*******************************/\n";
    std::cout << "/*       END OF TESTS          */\n";
    std::cout << "/*******************************/";

    clock_t end = clock();
    clock_t elapsed_seconds = (end - begin) / CLOCKS_PER_SEC;
    std::cout << "\n\t\telapsed: " << elapsed_seconds << '\n';

    std::cout << "\t\tPROGRAM ENDED SUCCESSFULLY!\n\n";
    return 0;
  }
  catch(Subscriber::BadSubscriber& e){
    std::cerr << e.badSubscriberException << '\n';
  }
  catch(...){
    std::cerr << "Unknown Exception thrown\n";
  }
}


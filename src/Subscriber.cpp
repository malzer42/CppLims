/**
 * File: Subscriber.cpp
 * Author: Pierre Abraham Mulamba
 * Created on 29 June 2020, 21 h 28
 * Modified on 29 June 2020, 23:43
 */

#include "Subscriber.h"
#include <string>
#include <iostream>

int Subscriber::countSubscriber_ = 0;

/**
 * Default constructor
 */
Subscriber::Subscriber() {
    idNumber_ = "idNumber";
    firstName_ = "firstName";
    lastName_ = "lastName";
    age_ = 0;
    sin_ = "sin";
    countSubscriber_++;
}
Subscriber::~Subscriber()
{
  countSubscriber_--;
}

/**
 * Parameter constructor
 * @param idNumber
 * @param firstName
 * @param lastName
 * @param age
 * @param sin
 */

Subscriber::Subscriber(const std::string& idNumber,
                       const std::string& firstName,
                       const std::string& lastName,
                       unsigned short age, const std::string& sin)
  : idNumber_(std::move(idNumber)), firstName_(std::move(firstName)),
    lastName_(std::move(lastName)),age_(age), sin_(std::move(sin))
{
  //countSubscriber_++;
  const unsigned short MIN_AGE = 3;
  const unsigned short MAX_AGE = 140;
  if( age < MIN_AGE || MAX_AGE < age) throw Subscriber::BadSubscriber();
}

// Getter methods
/**
 * Get the idNumber_ attribute
 * @return idNumber_
 */
const std::string& Subscriber::getIdNumber() const
{
  return idNumber_;
}

const std::string& Subscriber::getFirstName() const
{
  return firstName_;
}

const std::string& Subscriber::getLastName()const
{
  return lastName_;
}

const std::string& Subscriber::getSin()const
{
  return sin_;
}

unsigned short Subscriber::getAge()const
{
  return age_;
}

// Setter methods
/**
 * Set the idNumber_ attribute
 * @param idNumber
 */
void Subscriber::setIdNumber(const std::string& idNumber)
{
  idNumber_ = idNumber;
}

/**
 * Set the firstName_ attribute
 * @param firstName
 */
void Subscriber::setFirstName(const std::string& firstName)
{
  firstName_ = firstName;
}

/**
 * Set the lastName_ attribute
 * @param lastName
 */
void Subscriber::setLastName(const std::string& lastName){
    lastName_ = lastName;
}

/**
 * Set the age attribute
 * @param age
 */
void Subscriber::setAge(unsigned short age)
{
  age_ = age;
}

/**
 * Set the sin_ attribute
 * @param sin
 */
void Subscriber::setSin(const std::string& sin)
{
  sin_ = sin;
}

/**
 * Copy constructor
 * @param orig
 */
Subscriber::Subscriber(const Subscriber& orig)
  : idNumber_(orig.getIdNumber()), firstName_(orig.getFirstName()),
    lastName_(orig.getLastName()), age_(orig.getAge()), sin_(orig.getSin())
{
}

/**
 * Move constructor
 * @param orig
 */
Subscriber::Subscriber(Subscriber&& orig)noexcept
  : idNumber_(""), firstName_(""), lastName_(""), age_(0), sin_("")
{
  idNumber_ = orig.getIdNumber();
  firstName_ = orig.getFirstName();
  lastName_ = orig.getLastName();
  age_ = orig.getAge();
  sin_ = orig.getSin();
  orig.setIdNumber("");
  orig.setFirstName("");
  orig.setLastName("");
  orig.setAge(0);
  orig.setSin("");
}


/**
 * Copy assignment
 * @param subscriber
 * @return *this
 */
Subscriber& Subscriber::operator=(const Subscriber& orig)
{
  if(this != &orig){
    idNumber_ = orig.getIdNumber();
    firstName_ = orig.getFirstName();
    lastName_ = orig.getLastName();
    age_ = orig.getAge();
    sin_ = orig.getSin();
  }
  return *this;
}

/**
 * Movement assignment
 * @param subscriber
 * @return *this
 */
Subscriber& Subscriber::operator=(Subscriber&& orig)noexcept
{
  if (this != &orig){
    idNumber_ = "";
    firstName_ = "";
    lastName_ = "";
    age_ = 0;
    sin_ = "";

    idNumber_ = orig.getIdNumber();
    firstName_ = orig.getFirstName();
    lastName_ = orig.getLastName();
    age_ = orig.getAge();
    sin_ = orig.getSin();

    orig.setIdNumber("");
    orig.setFirstName("");
    orig.setLastName("");
    orig.setAge(0);
    orig.setSin("");
  }
  return *this;
}

/**
 * Printing the instance of class Subscriber
 */
void Subscriber::print()const
{
  std::cout << this->getFirstName()
            << " , " << this->getLastName()<<". "
            << this->getAge() << " y.o. #"
            << this->getIdNumber() <<". "
            << this->getCountSubscriber() <<'\n';
}


std::ostream& operator<<(std::ostream& out, const Subscriber& sub)
{
  out << sub.getCountSubscriber()
      << ". " << sub.getIdNumber() <<". "
      << sub.getFirstName() <<'\n';
  return out;
}

std::istream& operator>>(std::istream& in, Subscriber& sub)
{
  std::cout << "\nEnter the Id number: ";
  in >> sub.idNumber_;
  std::cout << "Enter the first name: ";
  in >> sub.firstName_;
  std::cout << "Enter the last name: ";
  in >> sub.lastName_;
  std::cout << "Enter the age: ";
  in >> sub.age_;
  std::cout << "Enter the sin number: ";
  in >> sub.sin_;
  return in;
}

//int Subscriber::getCountSubscriber()
//{
//  return countSubscriber_;
//}

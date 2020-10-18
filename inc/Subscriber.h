/**
 * File: Subscriber.h
 * Author(s): Pierre Abraham Mulamba
 * Created (modified): 20200629, 21:28 (20200711), 22:52
 * Description: Definition of the class Subscriber
 * Usage: To be included as header file in the Subscriber.cpp
 */


#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <exception>

class Subscriber {
public:
  // Ctor
  Subscriber();
  Subscriber(const std::string& idNumber = "", const std::string& firstName = "",
             const std::string& lastName = "", unsigned short age = 0,
             const std::string& sin = "");
  Subscriber(const Subscriber& orig); // Copy Ctor
  Subscriber(Subscriber&& orig)noexcept; // Move Ctor
  Subscriber& operator=(const Subscriber& subscriber); //! Copy assignment
  Subscriber& operator=(Subscriber&& subscriber)noexcept;// noexcept; //! Move
  // Exception
  class BadSubscriber : public std::exception {
  public:
    const std::string badSubscriberException = "BadSubscriberError\n";
  };

  class BadNameSize : public std::exception{
  public:
    const std::string badNameSize = "BadNameSizeError\n";
  };

  ~Subscriber(); // Dtor
  // Getter methods
  const std::string& getIdNumber()const;
  const std::string& getFirstName()const;
  const std::string& getLastName()const;
  unsigned short getAge()const;
  const std::string& getSin()const;
  // Setter methods
  void setIdNumber(const std::string& idNumber);
  void setFirstName(const std::string& firstName);
  void setLastName(const std::string& lastName);
  void setAge(unsigned short age);
  void setSin(const std::string& sin);
  void print()const;

  friend std::ostream& operator<<(std::ostream& out, const Subscriber&);
  friend std::istream& operator>>(std::istream& in, Subscriber&);

  static int getCountSubscriber(){return countSubscriber_;};

private:
  std::string idNumber_;
  std::string firstName_;
  std::string lastName_;
  unsigned short age_;
  std::string sin_;
  static int countSubscriber_;

};

#endif /* SUBSCRIBER_H */


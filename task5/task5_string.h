#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <exception>
#include <iostream>

#define ERROR 1 // 0 = no exception safety, 1 = strong exception safety


class buffer_overflow : public std::exception
{
public:
    virtual const char *what() const throw() { return "String too long!"; }
};

class String
{
public:

  String(); // default constructor
  String(const char* s); // copy constructor
  String(const String& s); // copy constructor

  virtual ~String(); 

  void init(const char * newData);
  void print() const;

  /* OPERATOR OVERLOADING INTERFACE */

  // operator=
  String& operator=(const String& s); 
  // end

  // operator +=
  String& operator+=(const String& s);
  String& operator+=(const char c);
  String& operator+=(const char *s);
  // end 

  // operator []
  char& operator[](const int i);
  // end

  // operator+
  friend String operator+(const String& s, const char* t);
  friend String operator+(const String&s, const String& t);
  friend String operator+(const char* s, const String& t);
  // end

  // cast to char* for use in f()
  operator char*() const; // f(char*)
  // end

  // relational operators ( <, >, <= )
  friend bool operator>(const String& s, const String& t);
  friend bool operator<=(const String& s, const String& t);
  // end
  
  // negation operator ( negation operator! )
  bool operator!();
  //end

  // standard input ( operator >> )
  friend std::istream& operator>>(std::istream& is, String& s);
  // end

private:

  char *mData;
  static const int c_size = 100;


  /* for error handling */
  int n;
  void check_size(int m)
  {
#if ERROR > 0                   // see ERROR above
      if (m + 1 > c_size)  // m characters plus NULL
          throw buffer_overflow();
#endif
  }

  void new_size(int m)
  {
      check_size(m);
      n = m;
  }
  /* end error handling */
};

#endif

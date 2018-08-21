#include "task5_string.h"

#include <cstring>
#include <exception>
#include <iostream>

using namespace std;

void String::init(const char * newData) {
    new_size(strlen(newData)); // check the length of newData ( for exception )
    std::memcpy(mData, newData, strlen(newData) + 1); 
}

String::String()
    : mData(new char[c_size])
{
    init(""); // when init, the string is empty
} 

String::String(const char* s)
	: mData(new char[c_size])
{
	init(s);                 
}

String::String(const String& s)
	: mData(new char[c_size]) 
{
	  init(s.mData);          
}

String::~String() { 
	  delete [] mData; 
}


void String::print() const {
	  std::cout << mData << std::endl;
}


/* IMPLEMENTS OPERATOR OVERLOADING */

// operator=
String& String::operator=(const String& s) { // from task3
    init(s.mData);
    return *this;
}
// end

// operator+=
String& String::operator+=(const String& s)
{
    new_size(n + s.n);
    strncat(mData, s.mData, c_size);
    return *this;
}

String& String::operator+=(const char c)
{
    char s[8] = { c };

    new_size(n + 1);
    strncat(mData, s, c_size);
    return *this;
}

String& String::operator+=(const char *s)
{
    new_size(n + strlen(s));
    strncat(mData, s, c_size);
    return *this;
}
// end

// operator []
char& String::operator[](const int i) { return mData[i]; }
// end

// operator+
String operator+(const String& s, const char* t) { 
    String temp(s);
    // Concatenate
    // concatenate t to String s ( s.mData + t )
    temp.new_size(temp.n + strlen(t));
    strncat(temp.mData, t, String::c_size);
    return temp;
}

String operator+(const String&s, const String& t) {
    // send to concatenate function right above
    return s + t.mData;
}

String operator+(const char* s, const String& t) {
    // Reverse Concatenate
    // send to String + String function right above
    return String(s) + t;
}
// end

// operator char*(): pass to void f(char*)
String::operator char* () const { return mData; }
// end

// relational operators
bool operator>(const String& s, const String& t) {
    return strncmp(s.mData, t.mData, String::c_size) > 0; // (s > t) == true
}

bool operator<=(const String& s, const String& t) {
    return !(s > t); // see above function: ( s > t ) == false
}
// end

// negation operator ( operator! )
bool String::operator!() {
    return n > 0; // if string not empty, the value is true
}
// end

// standard input ( operator >> )
istream& operator>>(istream& is, String& s) { 
    char buf[BUFSIZ];
    // input "is" to "buf", then return "is"
    is >> buf;
    s.init(buf);
    return is;
    // it supports chaining ( cin >> s1 >> s2 >> s3; )
}
// end

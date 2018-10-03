#include "task6_string.h"

using namespace std;

// init()

void String<char>::init(const char * newData) {
    new_size(strlen(newData));
    std::memcpy(mData, newData, strlen(newData) + 1);
}

void String<wchar_t>::init(const wchar_t * newData) {
    new_size(wcslen(newData));
    std::memcpy(mData, newData, wcslen(newData) + 1);
}


// constructor

String<char>::String()
    : mData(new char[c_size])
{
    init("");
}

String<wchar_t>::String()
    : mData(new wchar_t[c_size])
{
    init(L"");
}


// copy constructor 1 (?)

String<char>::String(const char* s)
    : mData(new char[c_size])
{
    init(s);
}

String<wchar_t>::String(const wchar_t* s)
    : mData(new wchar_t[c_size])
{
    init(s);
}


// copy constructor 2 (?)

String<char>::String(const String& s)
    : mData(new char[c_size])
{
    init(s.mData);
}

String<wchar_t>::String(const String& s)
    : mData(new wchar_t[c_size])
{
    init(s.mData);
}


// destructor

String<char>::~String() {
    delete[] mData;
}


String<wchar_t>::~String() {
    delete[] mData;
}


// print()

void String<char>::print() const {
    std::cout << mData << std::endl;
}

void String<wchar_t>::print() const {
    std::wcout << mData << std::endl;
}





/* IMPLEMENTS OPERATOR OVERLOADING */

// operator=

void swap(String<char>& s, String<char>& t)
{
    using std::swap;
    swap(s.mData, t.mData);
}
void swap(String<wchar_t>& s, String<wchar_t>& t)
{
    using std::swap;
    swap(s.mData, t.mData);
}

String<char>& String<char>::operator=(String s) {
    swap(*this, s);
    return *this;
}

String<wchar_t>& String<wchar_t>::operator=(String s) {
    swap(*this, s);
    return *this;
}





// operator+=

String<char>& String<char>::operator+=(const String<char>& s)
{
    new_size(n + s.n);
    strncat(mData, s.mData, c_size);
    return *this;
}
String<wchar_t>& String<wchar_t>::operator+=(const String<wchar_t>& s)
{
    new_size(n + s.n);
    wcsncat(mData, s.mData, c_size);
    return *this;
}


String<char>& String<char>::operator+=(const char c)
{
    char s[8] = { c };

    new_size(n + 1);
    strncat(mData, s, c_size);
    return *this;
}
String<wchar_t>& String<wchar_t>::operator+=(const wchar_t c)
{
    wchar_t s[8] = { c };

    new_size(n + 1);
    wcsncat(mData, s, c_size);
    return *this;
}






String<char>& String<char>::operator+=(const char *s)
{
    new_size(n + strlen(s));
    strncat(mData, s, c_size);
    return *this;
}
String<wchar_t>& String<wchar_t>::operator+=(const wchar_t *s)
{
    new_size(n + wcslen(s));
    wcsncat(mData, s, c_size);
    return *this;
}
String<wchar_t>& String<wchar_t>::operator+=(const char *s)
{   
    wchar_t wcharArr[16];
    mbstowcs(wcharArr, s, c_size);
    new_size(n + wcslen(wcharArr));
    wcsncat(mData, wcharArr, c_size);
    return *this;
}



// operator []

char& String<char>::operator[](const int i) { return mData[i]; }
wchar_t& String<wchar_t>::operator[](const int i) { return mData[i]; }






// operator+

String<char> operator+(const String<char>& s, const char* t) {
    String<char> temp(s);
    // concatenate t to String s ( s.mData + t )
    temp.new_size(temp.n + strlen(t));
    strncat(temp.mData, t, String<char>::c_size);
    return temp;
}

String<wchar_t> operator+(const String<wchar_t>& s, const wchar_t* t) {
    String<wchar_t> temp(s);
    temp.new_size(temp.n + wcslen(t));
    wcsncat(temp.mData, t, String<wchar_t>::c_size);
    return temp;
}


String<char> operator+(const String<char>&s, const String<char>& t) {
    // send to concatenate function right above
    return s + t.mData;
}
String<wchar_t> operator+(const String<wchar_t>&s, const String<wchar_t>& t) {
    // send to concatenate function right above
    return s + t.mData;
}




String<char> operator+(const char* s, const String<char>& t) {
    // Reverse Concatenate
    // send to String + String function right above
    return String<char>(s) + t;
}
String<wchar_t> operator+(const wchar_t* s, const String<wchar_t>& t) {
    // Reverse Concatenate
    // send to String + String function right above
    return String<wchar_t>(s) + t;
}
// end






// operator char*(): pass to void f(char*)

String<char>::operator char* () const { return mData; }
String<wchar_t>::operator wchar_t* () const { return mData; }

// end





// other operators

bool operator>(const String<char>& s, const String<char>& t) {
    return strncmp(s.mData, t.mData, String<char>::c_size) > 0; // (s > t) == true
}

bool operator>(const String<wchar_t>& s, const String<wchar_t>& t) {
    return wcsncmp(s.mData, t.mData, String<wchar_t>::c_size) > 0; // (s > t) == true
}



bool operator<=(const String<char>& s, const String<char>& t) {
    return !(s > t); // see above function: ( s > t ) == false
}

bool operator<=(const String<wchar_t>& s, const String<wchar_t>& t) {
    return !(s > t); // see above function: ( s > t ) == false
}




bool String<char>::operator!() {
    return n > 0; // if string is not empty, the value is true
}

bool String<wchar_t>::operator!() {
    return n > 0; // if string is not empty, the value is true
}
// end




// standard input ( operator >> )

istream& operator>>(istream& is, String<char>& s) {
    char buf[BUFSIZ];
    // input "is" to "buf", then return "is"
    is >> buf;
    s.init(buf);
    return is;
    // it supports chaining ( cin >> s1 >> s2 >> s3; )
}
wistream& operator>>(wistream& is, String<wchar_t>& s) {
    wchar_t buf[BUFSIZ];
    // input "is" to "buf", then return "is"
    is >> buf;
    s.init(buf);
    return is;
    // it supports chaining ( cin >> s1 >> s2 >> s3; )
}



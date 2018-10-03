#include "task6_string.h"

#include <exception>
#include <iostream>

/* To use with wchar_t:
- Change String<char> to String<wchar_t>
- Change cout to wcout
- Change "Hello" to L"Hello" 
- Change void f(char*) to void f(wchar_t*) ?
*/
using namespace std;

void f(char*) {}; // f(wchar_t*) if s1 s2 is wchar_t

int main(int argc, char **argv) {

    String<char> s1;
    String<char> s2;

    try {
        s1 += s2; 
        s1 += 'a'; // s1 prints "a"
        s1[0] = 'b'; // s1 prints "b"
        s1 += "Hello"; // s1 prints "bHello"
        s2 = "Hello" + s1; // s2 prints "HellobHello"
        f(s2);

        if (s2 > s1) // == false because 'H' < 'b' (ASCII code)
            cout << s1 << endl;
        if (s1 <= s2) // == false, see above
            cout << s2 << endl;

        if (!s1)  // if string is not empty
            cin >> s1; // rewrite s1 (?)
    }

    catch (buffer_overflow& e)
    {
        cout << e.what() << endl;
    }
    cout << endl << "Here they are:" << endl;

    cout << s1 << endl;
    cout << s2 << endl;

    getchar();
    getchar();
    return 0;
}

#include "task5_string.h"

#include <exception>
#include <iostream>

using namespace std;


void f(char*) {};

int main(int argc, char **argv) {  
    String s1, s2;

    try {
        s1 += s2; // done
        s1 += 'a'; // done
        s1[0] = 'b'; // done 
        s1 += "Hello"; // done
        s2 = "Hello" + s1; // done
        f(s2); // done, don't have to overload "cout <<"

        if (s2 > s1) // == false because 'H' < 'b' (ASCII code)
            cout << s1 << endl;
        if (s1 <= s2) // == false, see above
            cout << s2 << endl;

        if (!s1)  // if string not empty
            cin >> s1;
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

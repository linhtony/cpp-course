#include <iostream>
#include <vector>


using namespace std;

int num_of_digits; // must be 0, 3, 4 or 5 (0 is the cheat code)
void enterNumberOfDigits() {
    cout << "Enter number of digits in code: ";
    cin >> num_of_digits;
}

bool checkNumberOfDigits() {
    if (num_of_digits == 0 || num_of_digits == 3 || num_of_digits == 4 || num_of_digits == 5) { 
        return true; 
    }
    else {
        cout << "Invalid number of digits.." << endl;
        return false;
    }
}

int main() 
{   
    while (true) {
        enterNumberOfDigits();
        checkNumberOfDigits();

        if (checkNumberOfDigits() == true) {
        cout << "The number of digits is: " << num_of_digits << endl;
        break; 
        }
    }

    // TODO: keep coding...
}

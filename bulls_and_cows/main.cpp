#include <iostream>
#include <ctime>
#include <vector>


using namespace std;

// number of digits.. must be 0, 3, 4 or 5 (0 is the cheat code)
int num_of_digits; 


// check if the user type the number of digits correctly
bool checkNumberOfDigits() {
    if ( (num_of_digits == 0) || (num_of_digits == 3) || (num_of_digits == 4) || (num_of_digits == 5) ) { 
        return true; 
    }
    else {
        cout << "Invalid number of digits" << endl;
        return false;
    }
}






// generate a random int with 'n' digit, only be called if num_of_digits not 0
// @TODO: edit this function
int randomInt(int digit) {
    digit = num_of_digits;

    while (true) {
        srand(time(NULL));
        int random_number = rand();
        break;
    }
    return 0;
}

// called when num_of_digits is not 0
// @TODO: edit this function
int digitDefault(int digit) {

    switch (digit) {

    case (3):
        break;
    case (4):
        break;
    case (5):
        break;
    }

}

// called when the number of digits is 0
// @TODO: edit this function
int digitZero() {
    int digit = num_of_digits; // 0 only 
    return 0;
}

int main() 
{   
    // enter the number of digits and check for correctness
    while (true) {
        cout << "Enter number of digits in code: ";
        cin >> num_of_digits;

        if (checkNumberOfDigits() == true) {
        cout << "The number of digits is: " << num_of_digits << endl;
        break; 
        }
    }




    // TODO: keep coding...
    getchar();
    getchar();
}

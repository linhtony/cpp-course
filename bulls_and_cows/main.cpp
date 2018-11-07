#include <iostream>
#include <vector>
#include <ctime>
#include <random>


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


int main() 
{   
    vector<int> randomVector; 
    vector<int> manualVector;

    // enter the number of digits and check for correctness

    while (true) {
        cout << "Enter number of digits in code: ";
        cin >> num_of_digits;

        if (checkNumberOfDigits() == true) {
        break; 
        }
    }


    // output the code (for testing purpose)

    // TODO: add handler for num_of_digits = 0
    if (num_of_digits == 0) {
        cout << "Number to guess: " << endl;
    } 
    else {
        srand(time(NULL));
        vector<int> rd = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        random_shuffle(rd.begin(), rd.end());

        for (int i = 0; i < num_of_digits; i++) {
            randomVector.push_back(rd[i]);
        }

        cout << "Number to guess: ";

        for (int i = 0; i < num_of_digits; i++) {
            cout << randomVector[i] << " ";
        }

        randomVector.resize(num_of_digits);
    }



    // TODO: keep coding...
    getchar();
    getchar();
}

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


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

// count the number of digits in an integer
int digitsCount(int number) {
    int digits = 0;
    while (number) {
    number /= 10;
    digits++; 
    }
    return digits; 
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
    // TODO: add handler for num_of_digits = 0, when the guessed_num < num of digit (fill the first element with 0)
    if (num_of_digits == 0) {
        int manual_code;
        int manual_code_count;
        int manual_num_of_digits;
        
        cout << "Enter code: ";
        cin >> manual_code;

        manual_code_count = digitsCount(manual_code);

        while (true) {
            cout << "Enter number of digits in code: ";
            cin >> manual_num_of_digits;
            if (manual_num_of_digits == manual_code_count) {
                int array[manual_num_of_digits];

                for (int i = manual_num_of_digits - 1; i >= 0; i--) {
                array[i] = manual_code % 10;
                manual_code /= 10;
                }
                for (int i = 0; i <= manual_num_of_digits; i++) {
                manualVector.push_back( array[i] );
                }
                // out the vector
                for (int i = 0; i <= manual_code_count; i++) {
                cout << manualVector[i];
        }
                break;
            }
            else if (manual_num_of_digits > manual_code_count) {
                manualVector.push_back(0);
                int array[manual_num_of_digits];
                for (int i = 0; i <= manual_num_of_digits; i++) {
                manualVector.push_back( array[i] );
                }
                // out the vector
                for (int i = 0; i <= manual_code_count + 1; i++) {
                cout << manualVector[i];
                break;
                } 
            }
            else if (manual_num_of_digits < manual_code_count) {
                cout << "Invalid number of digits in code..! " << endl;
            }
        }

        cout << manual_code_count;
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

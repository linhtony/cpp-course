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

void extractToArray(int ar[], int length, int nb) {
    for (int i = length - 1; i >= 0; i--) {
        ar[i] = nb % 10;
        nb /= 10;
    }
}

// check for duplicates in custom code
bool duplicateCheck(int num) {
    int num_digit_count = digitsCount(num);

    int array[10];
    extractToArray(array, num_digit_count, num);

    for (int i = 0; i < num_digit_count; i++) {
        for (int j = i + 1; j < num_digit_count; j++) {
            if (array[i] == array[j])
                return true;
        }
    }
    return false;
}


int main() 
{   
    vector<int> randomVector; 
    vector<int> customVector;

    while (true) {
        cout << "Enter number of digits in code: ";
        cin >> num_of_digits;
        if ( checkNumberOfDigits() == true ) 
        break; 
    }

    // num_of_digits is 0
    if (num_of_digits == 0) {
        int custom_code;
        int custom_code_count;
        int custom_num_of_digits;
        
        while (true) {
            cout << "Enter code (custom code): ";
            cin >> custom_code;
            if ( duplicateCheck(custom_code) == true ) {
                cout << "Custom code contains duplicates! " << endl;
            }
            else
                break;
        }

        while (true) {
            cout << "Enter number of digits in code (custom number of digits): ";
            cin >> custom_num_of_digits;
            custom_code_count = digitsCount(custom_code);

            if (custom_num_of_digits == custom_code_count) {
                
                int array[10];
                extractToArray(array, custom_code_count, custom_code);

                for (int i = 0; i <= custom_code_count - 1; i++) {
                    customVector.push_back( array[i] );
                }

                // output the code for testing purpose
                cout << "Number to guess: ";
                for (int i = 0; i <= custom_code_count - 1; i++) {
                    cout << customVector[i] << " ";
                }
                cout << "" << endl;
                break;
            }
            else if (custom_num_of_digits == custom_code_count + 1) {
                customVector.push_back(0);

                int array[10];
                extractToArray(array, custom_code_count, custom_code);  

                for (int i = 0; i <= custom_code_count; i++) {
                    customVector.push_back(array[i]);
                }

                // output the code for testing purpose
                cout << "Number to guess: ";
                for (int i = 0; i <= custom_code_count; i++) {
                    cout << customVector[i] << " ";
                }
                cout << "" << endl;
                break;
            }
            else {
                cout << "Invalid custom number of digits in code..! " << endl;
            }
        }

        int code_guess;

        while (true) {
            cout << "Enter Guess: ";
            cin >> code_guess;

            int code_guess_count = digitsCount(code_guess);
            if (code_guess_count > custom_num_of_digits) {
                if (custom_num_of_digits == 1)
                    cout << "You can only enter " << custom_num_of_digits << " digit" << endl;
                else
                    cout << "You can only enter " << custom_num_of_digits << " digits" << endl;
            }
            else if (duplicateCheck(code_guess) == true || (code_guess_count + 1 < custom_num_of_digits)) {
                cout << "Each number must be different! " << endl;
            }
            else
                break;
        }
    }

    // num_of_digits is not 0
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
        cout << "" << endl;

        randomVector.resize(num_of_digits);

        int code_guess;

        while (true) {
            cout << "Enter Guess: ";
            cin >> code_guess;

            int code_guess_count = digitsCount(code_guess);
            if (code_guess_count > num_of_digits) {
                cout << "You can only enter " << num_of_digits << " digits" << endl;
            }
            else if ( (duplicateCheck(code_guess) == true) || (code_guess_count + 1 < num_of_digits) ) {
                cout << "Each number must be different! " << endl;
            }
            else
                break;
        }
    }



    // TODO: Match guess code with the secret code!



    cout << "\nPress any key to exit... " << endl;
    getchar();
    getchar();
    return 0;
}

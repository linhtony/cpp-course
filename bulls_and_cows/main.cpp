#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


using namespace std;
// TODO(tue): Don't use global variable if not really necessary.
// number of digits.. must be 0, 3, 4 or 5 (0 is the cheat code)
int num_of_digits;

// TODO(tue):
// 1. What happens if the set of supported num_of_digits is 10 instead of 4 as current?
// you still check if condition like current, don't you?
// What happens if checkNumberOfDigits() is called many times?
// Better way: initialize a static set of supported number.
// 2. Why do you need "else" ?
//
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

void extractToArray(int ar[], const int length, int nb) {
    for (int i = length - 1; i >= 0; i--) {
        ar[i] = nb % 10;
        nb /= 10;
    }
}

// check for duplicates in custom code
bool duplicateCheck(const int num) {
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

// return 1 if you win the game..
int winCondition(vector<int> vt, vector<int> vtGuess, int code_guess, int counter, int nod) {
    int win = 0;
    counter = digitsCount(code_guess);

    int array[10];
    extractToArray(array, nod, code_guess);

    for (int i = 0; i < nod; i++) {
        vtGuess.push_back(array[i]);
    }

    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < nod; i++) {
        if (vt.at(i) == vtGuess.at(i))
            bulls++;
        else {
            for (int j = 0; j < nod; j++) {
                if (vt.at(i) == vtGuess.at(j)) {
                    cows++;
                }
            }
        }
    }
    cout << bulls << " BULLS! " << endl;
    cout << cows << " COWS! " << endl;
    cout << "\n";
    if (bulls == nod)
        win = 1;
    return win;
}


int main() 
{   
    // TODO(tue): Please ensure consistency in naming variable, func.
    vector<int> customVector; // num_of_digits = 0
    vector<int> customVectorGuess; // guess vector (num_of_digits = 0)

    vector<int> randomVector; // num_of_digits not 0
    vector<int> randomVectorGuess; // guess vector (num_of_digits not 0)
    
    // TODO(tue): Can you wrap your code in seperated funtionality so that
    // your code will have nice layout, be clean and easy to read and maintain.
    // Eg: Create func and located outside main().
    while (true) {
        cout << "Enter number of digits in code: ";
        cin >> num_of_digits;
        if ( checkNumberOfDigits() == true ) 
        break; 
    }

    /* num_of_digits is 0 (custom) */
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
                cout << "\nNumber to guess: ";
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
                cout << "\nNumber to guess: ";
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
        
        // user begins to guess!
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
            else if ( (duplicateCheck(code_guess) == true) || (code_guess_count + 1 < custom_num_of_digits) ) {
                cout << "Each number must be different! " << endl;
            }
            else if (winCondition(customVector, customVectorGuess, code_guess, code_guess_count, custom_num_of_digits) == 1) {
                break;
            }
        }      
    }

    /* num_of_digits is not 0 (random) */
    else {
        srand(time(NULL));
        vector<int> rd = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        random_shuffle(rd.begin(), rd.end());

        for (int i = 0; i < num_of_digits; i++) {
            randomVector.push_back(rd[i]);
        }

        // output the code for testing purpose
        cout << "\nNumber to guess: ";
        for (int i = 0; i < num_of_digits; i++) {
            cout << randomVector[i] << " ";
        }
        cout << "" << endl;

        int code_guess;   
        
        // user begins to guess!
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
            else if (winCondition(randomVector, randomVectorGuess, code_guess,code_guess_count, num_of_digits) == 1) {
                break;
            }
        }
    }

    cout << "\nCongratulations, you win!!! Press any key to exit... " << endl;
    getchar();
    getchar();
    return 0;
}

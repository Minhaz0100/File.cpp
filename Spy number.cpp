#include <iostream>
using namespace std;

int main() {
    int num, sum = 0, product = 1, digit;

    cout << "Enter a number: ";
    cin >> num;

    int originalNum = num;

    
    while (num > 0) {
        digit = num % 10;   
        sum += digit;       
        product *= digit;    
        num /= 10;           
    }

   
    if (sum == product) {
        cout << originalNum << " is a Spy number." << endl;
    } else {
        cout << originalNum << " is not a Spy number." << endl;
    }

    return 0;
}

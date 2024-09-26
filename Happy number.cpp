#include <iostream>
using namespace std;

int sumOfSquares(int num) {
    int sum = 0, digit;
    while (num > 0) {
        digit = num % 10;  
        sum += digit * digit; 
        num /= 10;          
    }
    return sum;
}

bool isHappyNumber(int num) {
    int slow = num, fast = num;

    
    do {
        slow = sumOfSquares(slow);         
        fast = sumOfSquares(sumOfSquares(fast)); 
    } while (slow != fast);

    
    return (slow == 1);
}

int main() {
    int num;
    
    cout << "Enter a number: ";
    cin >> num;

    if (isHappyNumber(num)) {
        cout << num << " is a Happy number." << endl;
    } else {
        cout << num << " is not a Happy number." << endl;
    }

    return 0;
}

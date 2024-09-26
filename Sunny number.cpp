#include <iostream>
#include <cmath> 
using namespace std;

bool isPerfectSquare(int num) {
    int squareRoot = sqrt(num);
    return (squareRoot * squareRoot == num); 
}

int main() {
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    if (isPerfectSquare(num + 1)) {
        cout << num << " is a Sunny number." << endl;
    } else {
        cout << num << " is not a Sunny number." << endl;
    }

    return 0;
}

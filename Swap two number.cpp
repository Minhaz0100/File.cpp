#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;
    
   
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
   
    int temp = a;
    a = b;
    b = temp;
    
    
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Parser {
    string input;
    size_t pos;
public:
    Parser(string s) : input(s), pos(0) {}
    bool match(char expected) {
        if (pos < input.length() && input[pos] == expected) {
            pos++;
            return true;
        }
        return false;
    }
    bool S() {
        size_t save = pos;
        if (A() && match('a'))
            return true;
        pos = save;
        if (C() && match('e'))
            return true;
        pos = save;
        return false;
    }
    bool A() {
        size_t save = pos;
        if (match('a') && match('a') && B())
            return true;
        pos = save;
        if (match('a') && match('a') && match('b') && match('a'))
            return true;

        pos = save;
        return false;
    }
    bool B() {
        size_t save = pos;
        if (match('b') && match('b') && match('b'))
            return true;
        pos = save;
        return false;
    }
    bool C() {
        size_t save = pos;
        if (match('a') && match('a') && D())
            return true;
        pos = save;
        return false;
    }
bool D() {
        size_t save = pos;
        if (match('b') && match('b') && match('d'))
            return true;
        pos = save;
        return false;
    }
    bool parse() {
        return S() && pos == input.length();
    }
};
int main() {
    string str = "aabbde";
    Parser parser(str);
    if (parser.parse())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
    return 0;
    }

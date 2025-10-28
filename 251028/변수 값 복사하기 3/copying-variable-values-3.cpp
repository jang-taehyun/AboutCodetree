#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 5, c = 3;
    a = c;
    a += c;
    b -= c;

    cout << a << '\n' << b << '\n' << c;

    return 0;
}
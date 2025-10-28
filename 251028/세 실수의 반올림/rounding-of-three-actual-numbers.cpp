#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    cout << fixed;
    cout.precision(3);
    
    double f[3];
    for(int i=0; i<3; ++i)
        cin >> f[i];
    for(int i=0; i<3; ++i)
        cout << f[i] << '\n';
    return 0;
}
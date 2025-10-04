#include <iostream>

using namespace std;

int k = 32;
int main() {
    for(char i = ' '; i <= '~'; i++)
    cout << k++ << " " << i << endl; 

    return 0;
}
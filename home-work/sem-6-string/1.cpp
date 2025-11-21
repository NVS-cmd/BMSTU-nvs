#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> arr;
    string tmp;
    while (getline(cin, tmp)) {
        arr.push_back(tmp);
    }

    return 0;
}
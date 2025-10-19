#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    vector<int> vec;
    int inp;

    for (int i = 0; i < 20; i++) {
        cin >> inp;
        vec.push_back(inp);
    }

    cout << (find(vec.begin(), vec.end(), 7) != vec.end() ? "7 is among digits" : "7 is not among digits") << endl;

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int v : vec) cout << v << " ";
    cout << endl;

    return 0;
}
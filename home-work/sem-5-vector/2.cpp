#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    vector<int> vec;
    int inp;

    for (int i = 0; i < 10; i++) {
        cin >> inp;
        vec.push_back(inp);
    }

    for_each(vec.begin(), vec.end(), [](int x){
        cout << x*2 << " ";
    });
    cout << endl;

    return 0;
}
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
    
    for (int v : vec) cout << v << " ";
    cout << endl;

    vec.erase(remove_if(vec.begin(), vec.end(), [](int x){
        return x < 0;
    }), vec.end());

    for (int v : vec) cout << v << " ";

    return 0;
}
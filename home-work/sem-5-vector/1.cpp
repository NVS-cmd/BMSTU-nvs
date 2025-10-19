#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    vector<int> vec;
    
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }

    for_each(vec.begin(), vec.end(), [](int x){
        cout << x << " ";
    });
    cout << endl;

    return 0;
}
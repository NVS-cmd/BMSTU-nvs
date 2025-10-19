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

    cout << *max_element(vec.begin(), vec.end()) << endl;

    int mx = vec[0];
    for_each(vec.begin(), vec.end(), [&mx](int x){
        if (mx < x) {
            mx = x;
        }
    });

    cout << mx << endl;

    return 0;
}
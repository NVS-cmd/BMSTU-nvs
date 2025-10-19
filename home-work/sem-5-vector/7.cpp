#include <iostream>
#include <vector>
#include <algorithm>
#include <format>
#include <numeric>
using namespace std;

int main(){
    
    vector<double> vec;
    double inp;

    for (int i = 0; i < 10; i++) {
        cin >> inp;
        vec.push_back(inp);
    }

    vec.erase(remove_if(vec.begin(), vec.end(), [](double x){
        return !(-50 <= x && x <= 50);
    }), vec.end());

    auto mima = minmax_element(vec.begin(), vec.end());

    cout << format("Average is {}, min is {}, max is {}\n",
        double(accumulate(vec.begin(), vec.end(), 0)) / vec.size(),
        *mima.first,
        *mima.second);
    
    if (*mima.first <= -10) {
        cout << "There are temperatures that are below -10 degrees" << endl;
    }else {
        cout << "All temperatures are higher than -10 degrees" << endl;
    }

    return 0;
}
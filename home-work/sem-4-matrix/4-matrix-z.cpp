#include <iostream>
#include <cmath>
#include <vector>


int main(){
    int matrix[100][100];
    short n, num = 1;

    std::cout << "Enter size of n x n matrix:";
    std::cin >> n;

    short shape[4] = {0, n - 1, 0, n - 1};

    while (num <= pow(n, 2)){

        for (short i = shape[0]; i <= shape[1]; i++){
            matrix[shape[2]][i] = num++;
        }shape[2]++;

        for (short i = shape[2]; i <= shape[3]; i++){
            matrix[i][shape[1]] = num++;
        }shape[1]--;

        for (short i = shape[1]; i >= shape[0]; i--){
            matrix[shape[3]][i] = num++;
        }shape[3]--;

        for (short i = shape[3]; i >= shape[2]; i--){
            matrix[i][shape[0]] = num++;
        }shape[0]++;
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}
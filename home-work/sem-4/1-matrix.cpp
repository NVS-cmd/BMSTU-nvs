#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    cout << "Введите размер квадратной матрицы: ";
    cin >> N;
    cout << "Заполните числами: ";
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

// Отражения
    vector<vector<int>> M0(N, vector<int>(N)); // обычная матрица
    vector<vector<int>> M1(N, vector<int>(N)); // главная диагональ
    vector<vector<int>> M2(N, vector<int>(N)); // побочная диагональ
    vector<vector<int>> M3(N, vector<int>(N)); // вертикальная ось
    vector<vector<int>> M4(N, vector<int>(N)); // горизонтальная ось

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            M0[i][j] = A[i][j];
            M1[i][j] = A[j][i];
            M2[i][j] = A[N - 1 - j][N - 1 - i];
            M3[i][j] = A[i][N - 1 - j];
            M4[i][j] = A[N - 1 - i][j];
        }

    auto printMatrix = [&](const vector<vector<int>>& M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << M[i][j] << " ";
            cout << "\n";
    }
};
    cout << "Вывод обычной матрицы: " << endl;
    printMatrix(M0);
    cout << "Вывод перевернутой матрицы относительно главной диагонали: " << endl;
    printMatrix(M1);
    cout << "Вывод перевернутой матрицы относительно побочной диагонали: " << endl;
    printMatrix(M2);
    cout << "Зеркальное отражение относительно вертикальной оси: " << endl;
    printMatrix(M3);
    cout << "Зеркальное отражение относительно горизонтальной оси: " << endl;
    printMatrix(M4);

    return 0;
}
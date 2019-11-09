#include <iostream>
#include <ctime>
using namespace std;

void Initialization(int*** mat, int x, int y, int z){
    for(int j = 0; j < x; j++){
        mat[j] = new int* [y];
        for(int k = 0; k < y; k++){
            mat[j][k] = new int[z];
        }
    }
}

void Padding(int*** mat, int x, int y, int z, int max){
    srand(time(0));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < z; k++){
                mat[i][j][k] = (rand()%max + 1);
            }
        }
    }
}

void MultiMatrix(int*** mat1, int*** mat2, int*** mat3, int a, int b, int c, int d){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int k = 0; k < d; k++){
                for(int f = 0; f < c; f++){
                    mat3[i][j][k] += (mat1[i][j][f] * mat2[i][f][k]);
                }
            }
        }
    }
}

void Print(int*** mat, int x, int y, int z) {
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << mat[i][j][k] << '\t';
            }
            cout << endl;
        }
        cout << "\n\n\n";
    }
}

int main() {
    int a, b, c, d, max;
    int*** matrix1;
    int*** matrix2;
    int*** matrix3;
    cout << "\n\nThis program calculates the multiplication of 2 matrices\n";
    cout << "Enter size of matrices: (matrix1: a * b * c,  matrix2: a * c * d)";
    cout << "\na = ";
    cin >> a;
    cout << "\nb = ";
    cin >> b;
    cout << "\nc = ";
    cin >> c;
    cout << "\nd = ";
    cin >> d;
    cout << "\nTo not to enter matrix elements yourself, enter max element of your matrix and program will fill the matrix with random "
            "numbers\n";
    cout << "max element: ";
    cin >> max;
    matrix1 = new int** [a];
    matrix2 = new int** [a];
    matrix3 = new int** [a];
    Initialization(matrix1, a, b, c);
    Initialization(matrix2, a, c, d);
    Initialization(matrix3, a, b, d);
    Padding(matrix1, a, b, c, max);
    Padding(matrix2, a, c, d, max);
    cout << "Your matrices:\n First:\n\n";
    Print(matrix1, a, b, c);
    cout << "Second:\n\n";
    Print(matrix2, a, c, d);
    MultiMatrix(matrix1, matrix2, matrix3, a, b, c, d);
    cout << "Result of multiplication:\n";
    Print(matrix3, a, b, d);
    return 0;
}

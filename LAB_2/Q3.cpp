#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int** createMat(int r, int c);
void fillMat(int** mat, int r, int c);
void showMat(int** mat, int r, int c);
void calcSums(int** mat, int r, int c);
void transposeMat(int** mat, int r, int c);
void freeMat(int** mat, int r);

int main() {
    srand(static_cast<unsigned>(time(0)));

    int r, c;
    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns: ";
    cin >> c;

    if (r <= 0 || c <= 0) {
        cout << "Invalid dimensions!" << endl;
        return 1;
    }

    int** mat = createMat(r, c);
    fillMat(mat, r, c);

    cout << "Original Matrix:" << endl;
    showMat(mat, r, c);

    calcSums(mat, r, c);

    cout << "Transposed Matrix:" << endl;
    transposeMat(mat, r, c);

    freeMat(mat, r);

    return 0;
}

int** createMat(int r, int c) {
    int** mat = new int*[r];
    for (int i = 0; i < r; ++i) {
        mat[i] = new int[c];
    }
    return mat;
}

void fillMat(int** mat, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void showMat(int** mat, int r, int c) {
    for (int i = 0; i < r; ++i) {
        cout << "[ ";
        for (int j = 0; j < c; ++j) {
            cout << mat[i][j] << (j < c - 1 ? " " : "");
        }
        cout << " ]" << endl;
    }
}

void calcSums(int** mat, int r, int c) {
    int total = 0;
    int* rowSums = new int[r]();
    int* colSums = new int[c]();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            total += mat[i][j];
            rowSums[i] += mat[i][j];
            colSums[j] += mat[i][j];
        }
    }

    cout << "Sum of all elements: " << total << endl;

    cout << "Row sums: ";
    for (int i = 0; i < r; ++i) {
        cout << rowSums[i] << (i < r - 1 ? ", " : "");
    }
    cout << endl;

    cout << "Column sums: ";
    for (int i = 0; i < c; ++i) {
        cout << colSums[i] << (i < c - 1 ? ", " : "");
    }
    cout << endl;

    int maxRowSum = rowSums[0], maxRowIdx = 0;
    int maxColSum = colSums[0], maxColIdx = 0;

    for (int i = 1; i < r; ++i) {
        if (rowSums[i] > maxRowSum) {
            maxRowSum = rowSums[i];
            maxRowIdx = i;
        }
    }

    for (int i = 1; i < c; ++i) {
        if (colSums[i] > maxColSum) {
            maxColSum = colSums[i];
            maxColIdx = i;
        }
    }

    cout << "Row with highest sum: Row " << maxRowIdx + 1 << endl;
    cout << "Column with highest sum: Column " << maxColIdx + 1 << endl;

    delete[] rowSums;
    delete[] colSums;
}

void transposeMat(int** mat, int r, int c) {
    int** transposed = createMat(c, r);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            transposed[j][i] = mat[i][j];
        }
    }

    showMat(transposed, c, r);

    freeMat(transposed, c);
}

void freeMat(int** mat, int r) {
    for (int i = 0; i < r; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

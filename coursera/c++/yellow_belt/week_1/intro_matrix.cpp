#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows;
    int columns;

    vector<vector<int>> matrix;
public:
    Matrix() {
        rows = 0;
        columns = 0;
    }

    Matrix(int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("Out of range.");
        }

        if (num_cols == 0 || num_rows == 0) {
            num_rows = num_cols = 0;
        }
        rows = num_rows;
        columns = num_cols;
        matrix.assign(num_rows, vector<int>(num_cols));
    }

    int At(int row, int col) const {
        return matrix.at(row).at(col);
    }

    int& At(int row, int col) {
        return matrix.at(row).at(col);
    }

    int GetNumRows() const {
        return rows;
    }

    int GetNumColumns() const {
        return columns;
    }
};

bool IsEqualMatrixSize(const Matrix& first, const Matrix& second) {
    return (first.GetNumRows() == second.GetNumRows() && first.GetNumColumns() == second.GetNumColumns());
}

bool operator==(const Matrix& first, const Matrix& second) {
    if (!IsEqualMatrixSize(first, second)) return false;

    for(int i = 0; i < first.GetNumRows(); i++) {
        for(int j = 0; j < first.GetNumColumns(); j++) {
            if (first.At(i, j) != second.At(i, j)) return false;
        }
    }
    return true;
}

Matrix operator+(const Matrix& first, const Matrix& second) {
    if (!IsEqualMatrixSize(first, second)) throw invalid_argument("Matrix's sizes are not the same.");

    Matrix matrix(first.GetNumRows(), first.GetNumColumns());

    for(int i = 0; i < matrix.GetNumRows(); i++) {
        for(int j = 0; j < matrix.GetNumColumns(); j++) {
            matrix.At(i, j) = first.At(i, j) + second.At(i, j);
        }
    }

    return matrix;
}

istream& operator>>(istream& in, Matrix& matrix) {
    int num_rows, num_columns;
    in >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);

    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_columns; j++) {
            in >> matrix.At(i, j);
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns();

    for(int i = 0; i < matrix.GetNumRows(); i++) {
        out << endl;
        for(int j = 0; j < matrix.GetNumColumns(); j++) {
            out << matrix.At(i, j) << " ";
        }
    }
    return out;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class MATRIX {
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    // Constructor to initialize matrix with given size and default value
    MATRIX(int m, int n) : rows(m), cols(n) {
        data.resize(rows, vector<int>(cols, 0));
    }

    // Method to input matrix elements
    void inputMatrix() {
        cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Overload + operator to add two MATRIX objects
    MATRIX operator+(const MATRIX& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }

        MATRIX result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Method to display matrix elements
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> m >> n;

    // Create two MATRIX objects
    MATRIX matrix1(m, n);
    MATRIX matrix2(m, n);

    // Input elements for both matrices
    cout << "Matrix 1:" << endl;
    matrix1.inputMatrix();
    cout << "Matrix 2:" << endl;
    matrix2.inputMatrix();

    // Add the matrices
    try {
        MATRIX result = matrix1 + matrix2;

        // Display the result
        cout << "Resultant Matrix after addition:" << endl;
        result.display();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

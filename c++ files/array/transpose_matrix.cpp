#include<iostream>
using namespace std;

void print(int arr[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    // Define matrix
    int matrix[10][10];  // Maximum size assumed to be 10x10. You can adjust it as needed.

    // Input matrix elements
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print the original matrix
    cout << "Original Matrix:" << endl;
    print(matrix, n, m);

    cout << "Transpose:" << endl;

    // Transpose only for square matrices (n == m)
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        
        print(matrix, n, m);
    } else {
        // For non-square matrices, create a new matrix to store the transpose
        int transpose[10][10];  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                transpose[j][i] = matrix[i][j]; 
        }
        }

        
        print(transpose, m, n); 
    
    }

    return 0;
}

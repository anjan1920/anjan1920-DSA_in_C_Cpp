#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to generate the spiral matrix
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    // Initialize the matrix with -1 (indicating empty cells)
    vector<vector<int>> matrix(m, vector<int>(n, -1));

    // Extract Linked List data to a vector
    ListNode* temp = head;
    vector<int> list_Data;
    while (temp != NULL) {  // This will ensure the last node is included
        list_Data.push_back(temp->val);
        temp = temp->next;
    }

    // Start filling the matrix in a spiral order
    int list_index = 0;  // To keep track of linked list data

    // Spiral boundaries
    int top = 0, right = n - 1, bottom = m - 1, left = 0;
    int count = 0;
    int total_elements = m * n;  // Total number of elements in the matrix

    while (count < total_elements) {
        // Traverse from left to right
        for (int i = left; i <= right && count < total_elements; i++) {
            if (list_index < list_Data.size()) {
                matrix[top][i] = list_Data[list_index++];  // Fill with linked list data
            } else {
                matrix[top][i] = -1;  // Fill with -1 when data runs out
            }
            count++;
        }
        top++;  // Move the top boundary down

        // Traverse from top to bottom
        for (int i = top; i <= bottom && count < total_elements; i++) {
            if (list_index < list_Data.size()) {
                matrix[i][right] = list_Data[list_index++];
            } else {
                matrix[i][right] = -1;
            }
            count++;
        }
        right--;  // Move the right boundary left

        // Traverse from right to left
        for (int i = right; i >= left && count < total_elements; i--) {
            if (list_index < list_Data.size()) {
                matrix[bottom][i] = list_Data[list_index++];
            } else {
                matrix[bottom][i] = -1;
            }
            count++;
        }
        bottom--;  // Move the bottom boundary up

        // Traverse from bottom to top
        for (int i = bottom; i >= top && count < total_elements; i--) {
            if (list_index < list_Data.size()) {
                matrix[i][left] = list_Data[list_index++];
            } else {
                matrix[i][left] = -1;
            }
            count++;
        }
        left++;  // Move the left boundary right
    }

    return matrix;
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
    vector<int> listValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = createLinkedList(listValues);

    // Define the matrix dimensions (rows and columns)
    int m = 3, n = 4;

    // Generate the spiral matrix
    vector<vector<int>> result = spiralMatrix(m, n, head);

    // Print the resulting spiral matrix
    printMatrix(result);

    return 0;
}

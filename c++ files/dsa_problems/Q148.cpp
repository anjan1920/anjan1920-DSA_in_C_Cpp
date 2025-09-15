#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void merge(vector<int>& arr, int s, int e) {
    int mid = (s + e) / 2;

    // Calculating the length of left and right temp arrays
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    // Dynamically allocate arrays on the heap
    int* left = new int[lenLeft];
    int* right = new int[lenRight];

    // Copy the values from the main array to left
    int k = s; // Starting of the left array
    for (int i = 0; i < lenLeft; i++) {
        left[i] = arr[k];
        k++;
    }

    // Copy the values from the main array to the right temp array
    k = mid + 1; // Starting of the right array
    for (int i = 0; i < lenRight; i++) {
        right[i] = arr[k];
        k++;
    }

    // Merge the two arrays in sorted order using a two-pointer approach
    int left_index = 0;
    int right_index = 0;
    int mainArr_index = s;

    while (left_index < lenLeft && right_index < lenRight) {
        if (left[left_index] < right[right_index]) {
            // Insert the smaller element into the main array
            arr[mainArr_index] = left[left_index];
            mainArr_index++;
            left_index++;
        } else {
            // Insert the smaller element into the main array
            arr[mainArr_index] = right[right_index];
            mainArr_index++;
            right_index++;
        }
    }

    // If there are remaining elements in the left or right array
    if (left_index < lenLeft) {
        while (left_index < lenLeft) {
            arr[mainArr_index] = left[left_index];
            mainArr_index++;
            left_index++;
        }
    }
    if (right_index < lenRight) {
        while (right_index < lenRight) {
            arr[mainArr_index] = right[right_index];
            mainArr_index++;
            right_index++;
        }
    }

    // Deallocate the memory for temporary arrays
    delete[] left;
    delete[] right;
}

void mergeSort(vector<int>& arr, int s, int e) {
    // Base case
    if (s > e) return;
    if (s == e) return;

    int mid = (s + e) / 2;

    // Divide the left half
    mergeSort(arr, s, mid);
    // Divide the right half
    mergeSort(arr, mid + 1, e);
    // Merge them
    merge(arr, s, e);
}

ListNode* sortList(ListNode* head) {
    // Simple approach using O(n log n) time complexity
    // and O(n) space complexity for storing the list data in a vector
    if (!head) return nullptr;

    // Traverse the linked list and copy the elements into a vector/array
    vector<int> v;
    ListNode *temp = head;
    while (temp != nullptr) {
        v.push_back(temp->val);
        temp = temp->next;
    }

    // Sort the vector using merge sort
    int s = 0;
    int e = v.size() - 1;
    mergeSort(v, s, e);

    // Rebuild the sorted linked list
    temp = head;
    int i = 0;
    while (temp != nullptr) {
        temp->val = v[i];
        i++;
        temp = temp->next;
    }

    return head;
}

int main() {
    // Create a linked list for testing: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Sort the list
    head = sortList(head);

    // Print the sorted list
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    // Clean up memory
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}

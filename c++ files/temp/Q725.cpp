#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// create a linked list from a vector given a range [start, end)
ListNode* createLinkedList(const vector<int>& v, int start, int end) {
    if (start >= end) return nullptr;  // If the range is invalid, return an empty list

    ListNode* head = new ListNode(v[start]);  // Create the head node
    ListNode* current = head;
    
    for (int i = start + 1; i < end; i++) {
        current->next = new ListNode(v[i]);  // Create the remaining nodes
        current = current->next;
    }
    
    return head;  // Return the head of the newly created linked list
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {

    // Step-1
    // Extract the linked list data into a vector
    ListNode *temp = head;
    vector<int> v;
    int size = 0;
    while (temp != NULL) {
        v.push_back(temp->val);
        temp = temp->next;
        size++;
    }

    // Step-2
    // Check if size of linked list < k, then each part of k contains only one element,
    // and the last parts will be empty linked lists
    vector<ListNode*> ans;
    if (size < k) {
        for (int i = 0; i < k; i++) {
            if (i < size) {
                ans.push_back(new ListNode(v[i]));  // Make a single element LL
            } else {
                ans.push_back(nullptr);  // Empty list for remaining parts
            }
        }
        return ans;
    }

    // Step-3
    // Make a parts array which contains the sizes of each part
    
    int part_size_each = size / k;  // Initial size of each part
    int rem = size % k;  // Remaining nodes to distribute
    vector<int> parts(k, part_size_each);  // k-sized array to store part sizes

    int j = 0;
    while (rem != 0) {
        parts[j]++;
        rem--;
        j++;
    }

    // Step-4
    // Now that the parts array contains the actual sizes of each part,
    // construct linked lists of the appropriate sizes and push to vector
    int start = 0;  // Index to track the start of each part
    for (int i = 0; i < k; i++) {
        int part_size = parts[i];  // Size of the current part

        // Use the helper function to create the linked list for this part
        ans.push_back(createLinkedList(v, start, start + part_size));

        // Update the start index for the next part
        start += part_size;
    }

    return ans;  // Return the vector of linked lists
}

// Helper function to print the linked lists in the result vector
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /// Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 using a loop
    ListNode* head = new ListNode(1);  // Create the head node
    ListNode* current = head;

    for (int i = 2; i <= 7; i++) {  // Loop to add nodes from 2 to 7
        current->next = new ListNode(i);
        current = current->next;
    }

    int k = 3;  // Number of parts to split the linked list into

    // Split the list into k parts
    vector<ListNode*> result = splitListToParts(head, k);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << "Part " << i + 1 << ": ";
        printList(result[i]);
    }

    return 0;
}

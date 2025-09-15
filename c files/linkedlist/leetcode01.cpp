#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    // Function to create a linked list from a vector and return the head
    ListNode* createLinkedList(const vector<int>& ans) {
        if (ans.empty()) return nullptr; // Return nullptr if the vector is empty
        
        ListNode* head = new ListNode(ans[0]); // Create the head node
        ListNode* current = head; // Pointer to track the current node

        for (size_t i = 1; i < ans.size(); ++i) {
            current->next = new ListNode(ans[i]); // Create and link new nodes
            current = current->next; // Move to the next node
        }
        
        return head; // Return the head of the linked list
    }

    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        // Traverse the linked lists and store the digits in vectors
        while (temp1 != nullptr) {
            num1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            num2.push_back(temp2->val);
            temp2 = temp2->next;
        }
        
        // Reverse the vectors to process the digits from least significant to most significant
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // Perform addition on the vectors
        vector<int> ans;
        int carry = 0;
        int maxSize = max(num1.size(), num2.size()); // Get the maximum size

        for (int i = 0; i < maxSize; ++i) {
            int digit1 = (i < num1.size()) ? num1[i] : 0; // Use 0 if index is out of bounds
            int digit2 = (i < num2.size()) ? num2[i] : 0; // Use 0 if index is out of bounds
            int sum = digit1 + digit2 + carry;

            // If carry present
            if (sum > 9) {
                carry = sum / 10;
                ans.push_back(sum % 10);
            } else {
                // No carry
                carry = 0;
                ans.push_back(sum);
            }
        }

        // If there is a carry left after the final digit
        if (carry > 0) {
            ans.push_back(carry);
        }
        
        // Reverse the result vector to match the correct order
        reverse(ans.begin(), ans.end());

        // Create a linked list from the result vector and return it
        return createLinkedList(ans);
    }

    // Function to print a linked list
    void printLinkedList(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Creating linked list 1: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));

    // Creating linked list 2: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // Adding the two numbers
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Printing the result
    cout << "Result: ";
    sol.printLinkedList(result);

    // Clean up memory
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

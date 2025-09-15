#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Reverse a linked list
ListNode* reverseSLL(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // empty or single node = palindrome

        // Step 1: Find middle using slow-fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseSLL(slow->next);

        // Step 3: Compare both halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool isPali = true;
        while (p2 != NULL) {
            if (p1->val != p2->val) {
                isPali = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Step 4: Restore the list
        slow->next = reverseSLL(secondHalf);

        return isPali;
    }
};

// create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 1, 2, 1};
    ListNode* head = createList(vals);

    Solution sol;
    cout << (sol.isPalindrome(head) ? "true" : "false") << endl;

    cout << "List after palindrome check (restored): ";
    printList(head);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //using hash map approach
        //T.n = O(N)*O(n){map find}
        //S.c = O(N) space complexity
        /*
        map<ListNode*,int>mpp;

        ListNode* temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end())return true;
            mpp[temp]=1;
            temp = temp->next;
        }
        return false;
        */

        //using slow fast approach
        //T.n = O(n) s.c = O(1)

        ListNode* fast = head;
        ListNode* slow = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If fast and slow pointer points to the same node,
            // then the cycle is detected
            if (slow == fast) {
                return true;
            }
        }
    
        return false;
    }
};

int main() {
    // Creating nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create a cycle for testing
    head->next->next->next->next = head->next; // 4 -> 2 (cycle)

    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}

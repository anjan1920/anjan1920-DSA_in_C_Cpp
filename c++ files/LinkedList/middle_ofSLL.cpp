#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution1 {
public:
    int countLinkedList_size(ListNode* head) {
        if (head == NULL) return 0;
        ListNode* temp = head;
        int size = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    ListNode* middleNode(ListNode* head) {
        int size_count = countLinkedList_size(head);

        if (size_count == 0) return NULL;
        if (size_count == 1) return head;

        int position = size_count / 2 + 1;  
        ListNode* temp = head;
        int start = 1;

        while (start != position) {
            temp = temp->next;
            start++;
        }
        return temp;
    }
};


class Solution2 {
public:
    

    ListNode* middleNode(ListNode* head) {
        //using fast and slow method
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != NULL)
        {
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow=slow->next;
            }
        }
        //when length is even, slow points to len/2-th node
        //when length is odd, slow points to ceil(n/2)-th node
        //LeetCode requires: if two middles, return the second  
        //i.e when len is even the mid is len/2 + 1 th node
        
        //so this verrion will works
        //   while (fast != NULL) {
        //     fast = fast->next;
        //     if (fast != NULL) {
        //         fast = fast->next;
        //         slow = slow->next;
        //     }
        // }

        return slow; 
    }
};

ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(); // dummy head
    ListNode* curr = dummy;

    for (int val : nums) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }

    return dummy->next; // skip dummy head
}

// function to print linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int>data = {1,5,6,7,8,10};
    // create linked list from vector
    ListNode* head = createLinkedList(data);

    // print linked list
    printLinkedList(head);
    Solution2* obj = new Solution2();
    ListNode* middle = obj->middleNode(head);
    printLinkedList(middle);






}
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution0 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> arr;

        // Add odd elements to array
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // Add even elements to array
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // Replace values in LL with array
        temp = head;
        int i = 0;
        while (i < arr.size() && temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
        //T.n = O(n/2)+O(n/2)
        //S.c = O(n)
    }
};

class Solution1 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = even;

        while (even && even->next) {
            // connect odd -> odd
            odd->next = odd->next->next;
            odd = odd->next;  

            // connect even -> even
            even->next = even->next->next;
            even = even->next;  
        }

        // at the end, link odd list with even list
        odd->next = firstEven;
        return temp;
        //t.n = O(n)
        //s.c =  O(1)
    }
};

void printLL(ListNode* head){
    while (head != NULL)
    {
        cout<<head->val;
        if(head->next == NULL)cout<<"-->NULL";
        else cout<<"-->";
        head = head->next;
    }
    cout<<endl;
    
}
ListNode* createArr_to_LL(vector<int>&arr){
    
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        ListNode* newNode = new ListNode(arr[i]);
        temp->next = newNode;
        temp = temp->next;   
    }

    return head;
}

    


int main(){
    vector<int>arr = {1,2,3,4,5,6};
    //create LL
    ListNode* head = createArr_to_LL(arr);
    Solution0* obj1 = new Solution0();
    printLL(head);
    obj1->oddEvenList(head);
    printLL(head);
    
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode *curr=head;
        int count=0;
        while(curr){
            curr=curr->next;
            count++;
        }
        curr=head;
        int x=0;
        ListNode *prev=nullptr;
        while(x<count-n){
            x++;
            prev=curr;
            curr=curr->next;
        }
        if(prev==nullptr) return curr->next;
        prev->next=curr->next;
        delete curr;
        return head;
    }
};

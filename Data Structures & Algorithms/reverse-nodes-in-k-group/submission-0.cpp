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
    void reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return;
        ListNode *curr=head;
        ListNode *prev=nullptr;
        while(curr!=nullptr){
            ListNode *nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *curr=head;
        ListNode *prev=nullptr;
        ListNode *oldcurr1=nullptr;
        ListNode *val=nullptr;
        while(curr){
            int x=0;
            ListNode *curr1=curr;
            while(x<k&&curr){
                prev=curr;
                curr=curr->next;
                x++;
            }
            if(x<k&&curr1==head) val=head;
            prev->next=nullptr;
            if(x==k&&curr1==head){
                reverseList(curr1);
                curr1->next=curr;
                val=prev;
                oldcurr1=curr1;
            }
            else if(x==k&&curr1!=head){
                reverseList(curr1);
                oldcurr1->next=prev;
                curr1->next=curr;
                oldcurr1=curr1;
            }
        }
        return val;
    }
};

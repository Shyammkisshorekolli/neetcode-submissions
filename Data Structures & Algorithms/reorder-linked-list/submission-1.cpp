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
    ListNode *left;
    void solve(ListNode* right){
        if(!right) return;
        solve(right->next);
        if(!left) return;
        if(left==right||left->next==right){
            right->next=nullptr;
            left=nullptr;
            return;
        }
        ListNode* nextleft=left->next;
        left->next=right;
        right->next=nextleft;
        left=nextleft;
    }
    void reorderList(ListNode* head) {
        left=head;
        solve(head);
    }
};

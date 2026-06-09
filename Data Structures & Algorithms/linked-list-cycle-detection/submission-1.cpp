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
    bool hasCycle(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return false;
        unordered_set<ListNode*>sets;
        ListNode *curr=head;
        while(curr){
            if(sets.find(curr)!=sets.end()) return true;
            sets.insert(curr);
            curr=curr->next;
        }
        return false;
    }
};

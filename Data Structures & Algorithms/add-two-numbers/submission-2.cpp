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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1=l1;
        ListNode *curr2=l2;
        ListNode *curr3=new ListNode(0);
        ListNode *curr3_=curr3;
        int leftover=0;
        while(curr1&&curr2){
            curr3->val= (curr1->val+curr2->val)%10 + leftover;
            leftover=(curr1->val+curr2->val)/10;
            curr1=curr1->next;
            curr2=curr2->next;
            if(curr1&&curr2){
                curr3->next=new ListNode(0);
                curr3=curr3->next;
            }
        }
        if(!curr1&&!curr2){
            if(leftover==0){
                curr3->next=nullptr;
                return curr3_;
            }
            else{
                curr3->next=new ListNode(leftover);
                curr3->next->next=nullptr;
                return curr3_;
            }
        }
        
        curr3->next=new ListNode(0);
        curr3=curr3->next;

        while(curr1){
            curr3->val=(curr1->val+leftover)%10;
            leftover=(curr1->val+leftover)/10;
            curr1=curr1->next;
            if(curr1){
                curr3->next=new ListNode(0);
                curr3=curr3->next;
            }
        }
        while(curr2){
            curr3->val=(curr2->val+leftover)%10;
            leftover=(curr2->val+leftover)/10;
            curr2=curr2->next;
            if(curr2){
                curr3->next=new ListNode(0);
                curr3=curr3->next;
            }
        }
        if(leftover!=0){
            curr3->next=new ListNode(leftover);
            curr3->next->next=nullptr;
        }
        else curr3->next=nullptr;
        return curr3_;
    }
};

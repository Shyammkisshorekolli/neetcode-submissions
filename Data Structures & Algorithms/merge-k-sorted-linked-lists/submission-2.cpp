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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode *curr1=list1;
        ListNode *curr2=list2;
        ListNode *prev=nullptr;
        ListNode *temp=nullptr;
        if(list1->val<=list2->val) temp=list1;
        else temp=list2;
        while(curr1&&curr2){
            if(curr1->val<=curr2->val){
                if(prev) prev->next=curr1;
                while(curr1&&curr1->val<=curr2->val){
                    prev=curr1;
                    curr1=curr1->next;
                }
                ListNode *nextnode=prev->next;
                curr1=nextnode;
            }
            else{
                if(prev) prev->next=curr2;
                while(curr2&&curr2->val<=curr1->val){
                    prev=curr2;
                    curr2=curr2->next;
                }
                ListNode *nextnode=prev->next;
                curr2=nextnode;
            }
            
        }
        while(curr1){

            prev->next=curr1;
            prev=prev->next;
            curr1=curr1->next;
        }
        while(curr2){
            prev->next=curr2;
            prev=prev->next;
            curr2=curr2->next;
        }
        prev->next=nullptr;
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0||n==1) return nullptr;
        for(int i=0;i<n-1;i++){
            ListNode* curr1=lists[i];
            ListNode* curr2=lists[i+1];
            ListNode* curr=mergeTwoLists(curr1,curr2);
            lists[i+1]=curr;
        }
        return lists[n-1];
    }
};

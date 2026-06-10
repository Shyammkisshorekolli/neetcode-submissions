/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        unordered_map<Node*,Node*>maps;
        Node *curr=head;
        Node *copy=new Node(curr->val);
        Node *copy_=copy;
        while(curr){
            maps[curr]=copy;
            if(curr->next){
                copy->next=new Node(curr->next->val);
                copy=copy->next;
            }
            curr=curr->next;
        }
        copy->next=nullptr;
        curr=head;
        copy=copy_;
        while(curr){
            if(curr->random) copy->random=maps[curr->random];
            else copy->random=nullptr;
            copy=copy->next;
            curr=curr->next;
        }
        return copy_;
    }
};

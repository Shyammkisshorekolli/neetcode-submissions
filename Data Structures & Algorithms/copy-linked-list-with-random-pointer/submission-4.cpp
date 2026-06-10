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
        if (!head) return nullptr;

        unordered_map<Node*, Node*> maps;

        Node* curr = head;

        while (curr) {
            maps[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr) {
            maps[curr]->next = maps[curr->next];
            maps[curr]->random = maps[curr->random];
            curr = curr->next;
        }

        return maps[head];
    }
};

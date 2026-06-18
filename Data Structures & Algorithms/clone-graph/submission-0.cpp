/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* bfs(Node* node){
        unordered_map<Node*,Node*>maps;
        Node* root=new Node(node->val);
        maps[node]=root;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(auto &ng:curr->neighbors){
                if(maps.find(ng)==maps.end()){
                    q.push(ng);
                    maps[ng]=new Node(ng->val);

                }
                maps[curr]->neighbors.push_back(maps[ng]);
            }
        }
        return maps[node];
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        return bfs(node);
    }
};

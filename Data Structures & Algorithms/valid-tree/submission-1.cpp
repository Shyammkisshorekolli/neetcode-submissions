class Solution {
public:
    void dfs(vector<vector<int>>& graph,
             int node,
             vector<bool>& vis){

        vis[node] = true;

        for(int nei : graph[node]){
            if(!vis[nei])
                dfs(graph, nei, vis);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1)
            return false;

        vector<vector<int>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);

        dfs(graph,0,vis);

        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }

        return true;
    }
};
class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state,vector<int>&ans) {

        if(state[node] == 1) return true;  
        if(state[node] == 2) return false;  
        state[node] = 1;    
        for(int nei : graph[node]) {
            if(dfs(nei, graph, state,ans)) return true;
        }
        state[node] = 2;
        ans.push_back(node);   
        return false;
    }

    vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int>ans;
        for(auto& p : prerequisites)
            graph[p[0]].push_back(p[1]);

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(dfs(i, graph, state,ans)) return {};
        }

        return ans;
    }
};
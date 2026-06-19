class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state) {

        if(state[node] == 1)
            return true;    // cycle

        if(state[node] == 2)
            return false;   // already processed

        state[node] = 1;    // visiting

        for(int nei : graph[node]) {
            if(dfs(nei, graph, state))
                return true;
        }

        state[node] = 2;    // visited
        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for(auto& p : prerequisites)
            graph[p[0]].push_back(p[1]);

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(dfs(i, graph, state))
                return false;
        }

        return true;
    }
};
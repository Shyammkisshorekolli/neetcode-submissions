class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&maps,int i,vector<bool>&visit){
        if(visit[i]) return;
        visit[i]=true;
        for(auto &mp:maps[i]){
            dfs(maps,mp,visit);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>maps;
        for(int i=0;i<edges.size();i++){
            maps[edges[i][0]].push_back(edges[i][1]);
            maps[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visit(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(visit[i]) continue;
            dfs(maps,i,visit);
            count++;
        }
        return count;
    }
};

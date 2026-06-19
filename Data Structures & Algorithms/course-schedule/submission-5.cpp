class Solution {
public:
    bool cycle=false;
    void dfs(unordered_map<int,vector<int>>&maps,int i,vector<bool>&state){
        if(cycle) return;
        if(state[i]==false){
            cycle=true;
            return;
        }
        state[i]=false;
        for(auto &mp : maps[i]){
            if(maps.find(mp)==maps.end()) continue;
            dfs(maps,mp,state);
        }
        state[i]=true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>maps;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            maps[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            vector<bool>state(numCourses,true);
            if(maps.find(i)==maps.end()) continue;
            dfs(maps,i,state);
            if(cycle){
                return false;
                break;
            }
        }
        return true;
    }
};

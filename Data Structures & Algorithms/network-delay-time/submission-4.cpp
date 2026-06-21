class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        unordered_map<int,vector<vector<int>>>maps;
        for(int i=0;i<times.size();i++){
            maps[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        queue<pair<int,int>>q;
        q.push({k,0});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto &mp:maps[x]){
                int node=mp[0];
                int t=mp[1];
                if(y+t<time[node]){
                    time[node]=y+t;
                    q.push({node,time[node]});
                }
            }
        }
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX)
                return -1;

            ans = max(ans, time[i]);
        }

        return ans;
    }
};

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
                auto part=mp;
                int node=part[0];
                int t=part[1];
                if(y+t>=time[node]) continue;
                time[node]=min(y+t,time[node]);
                q.push({node,time[node]});
            }
        }
        int max_time=INT_MIN;
        for(int i=1;i<n+1;i++){
            max_time=max(max_time,time[i]);
        }
        if(max_time==INT_MAX) return -1;
        else return max_time;
    }
};

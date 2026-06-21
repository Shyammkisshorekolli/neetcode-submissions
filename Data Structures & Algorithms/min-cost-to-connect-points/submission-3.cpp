class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        unordered_map<int, vector<pair<int,int>>> maps;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int d = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);

                maps[i].push_back({j, d});
                maps[j].push_back({i, d});
            }
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        vector<int> distance(n, INT_MAX);
        vector<bool> vis(n, false);

        q.push({0, 0});
        distance[0] = 0;

        int ans = 0;

        while(!q.empty()) {

            auto [dis, idn] = q.top();
            q.pop();

            if(vis[idn]) continue;

            vis[idn] = true;
            ans += dis;

            for(auto &mp : maps[idn]) {

                int i = mp.first;
                int d = mp.second;

                if(!vis[i] && d < distance[i]) {

                    distance[i] = d;
                    q.push({distance[i], i});
                }
            }
        }

        return ans;
    }
};
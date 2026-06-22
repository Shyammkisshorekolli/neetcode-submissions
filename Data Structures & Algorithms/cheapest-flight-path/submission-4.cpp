class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, vector<vector<int>>> maps;

        for (auto &f : flights) {
            maps[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > q;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        q.push({0, src, -1});
        dist[src][0] = 0;

        while (!q.empty()) {

            auto curr = q.top();
            q.pop();

            int price = curr[0];
            int node  = curr[1];
            int stop  = curr[2];

            if (node == dst)
                return price;

            if (stop >= k)
                continue;

            for (auto &mp : maps[node]) {

                int next = mp[0];
                int cost = mp[1];

                int newCost = price + cost;
                int newStop = stop + 1;

                if (newCost < dist[next][newStop + 1]) {
                    dist[next][newStop + 1] = newCost;
                    q.push({newCost, next, newStop});
                }
            }
        }

        return -1;
    }
};
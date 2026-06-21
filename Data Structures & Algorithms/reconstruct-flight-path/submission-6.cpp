class Solution {
public:
    unordered_map<string,
        priority_queue<string, vector<string>, greater<string>>> maps;

    vector<string> ans;

    void dfs(string src) {
        while (!maps[src].empty()) {
            string next = maps[src].top();
            maps[src].pop();
            dfs(next);
        }
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &t : tickets) {
            maps[t[0]].push(t[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
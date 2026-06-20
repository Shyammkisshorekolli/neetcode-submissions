class Solution {
public:
    vector<vector<int>> ans;

    bool dfs(unordered_map<int, vector<int>>& maps, int i,
             vector<int>& state, unordered_map<int, int>& parent) {

        if (state[i] == 1) return true;
        if (state[i] == 2) return false;

        state[i] = 1;

        for (auto& mp : maps[i]) {
            if (parent.find(i) != parent.end() && mp == parent[i])
                continue;

            parent[mp] = i;

            if (dfs(maps, mp, state, parent)) {
                ans.push_back({mp, parent[mp]});
                return true;
            }
        }

        state[i] = 2;
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> maps;

    for (int i = 0; i < edges.size(); i++) {
        maps[edges[i][0]].push_back(edges[i][1]);
        maps[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> state(edges.size() + 1, 0);
    unordered_map<int, int> parent;

    dfs(maps, 1, state, parent);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    unordered_set<string> st;

    for (auto &v : ans) {
        int a = min(v[0], v[1]);
        int b = max(v[0], v[1]);

        st.insert(to_string(a) + "#" + to_string(b));
    }

    for (int i = edges.size() - 1; i >= 0; i--) {
        int a = min(edges[i][0], edges[i][1]);
        int b = max(edges[i][0], edges[i][1]);

        string key = to_string(a) + "#" + to_string(b);

        if (st.count(key))
            return edges[i];
    }

    return {};
}
};
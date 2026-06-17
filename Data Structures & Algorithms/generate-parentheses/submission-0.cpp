class Solution {
public:
    void dfs(int n, int right, int left, string &s, vector<string>& ans) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (right < 0 || left < 0) return;

        if (right > 0) {
            s += '(';
            dfs(n, right - 1, left, s, ans);
            s.pop_back();
        }

        if (left > right) {
            s += ')';
            dfs(n, right, left - 1, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        dfs(n, n, n, s, ans);
        return ans;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void dfs(string s, string p, int i,
             vector<string>& ans,
             vector<vector<string>>& final) {

        if (i == s.length()) {
            if (p.empty())
                final.push_back(ans);
            return;
        }

        p += s[i];

        if (isPalindrome(p)) {
            ans.push_back(p);

            dfs(s, "", i + 1, ans, final);

            ans.pop_back(); // backtrack
        }

        dfs(s, p, i + 1, ans, final);
    }

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> final;
        dfs(s, "", 0, ans, final);
        return final;
    }
};
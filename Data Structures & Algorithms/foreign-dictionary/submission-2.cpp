class Solution {
public:
    bool valid = true;
    unordered_map<char, vector<char>> maps;
    unordered_set<char> sets;
    vector<char> ans;

    void isvalid(string s, string t) {
        int n = min(s.length(), t.length());

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                maps[s[i]].push_back(t[i]);
                return;
            }
        }

        if (s.length() > t.length()) {
            valid = false;
        }
    }

    bool dfs(char mt, vector<int>& alp) {

        if (alp[mt - 'a'] == 1) return false; 

        if (alp[mt - 'a'] == 2) return true;  

        alp[mt - 'a'] = 1;

        for (auto& small : maps[mt]) {
            if (!dfs(small, alp)) return false;
        }

        alp[mt - 'a'] = 2;
        ans.push_back(mt);

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        for (auto& word : words) {
            for (char c : word) {
                sets.insert(c);
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            isvalid(words[i], words[i + 1]);

            if (!valid) return "";
        }

        vector<int> alp(26, 0);

        for (auto& st : sets) {
            if (alp[st - 'a'] == 0) {
                if (!dfs(st, alp)) return "";
            }
        }

        reverse(ans.begin(), ans.end());

        string final = "";

        for (char c : ans) {
            final += c;
        }

        return final;
    }
};
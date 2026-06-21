class Solution {
public:
    bool istrans(string s, string t) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) count++;
        }

        return count == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        bool exists = false;

        for (auto &word : wordList) {
            if (word == endWord) {
                exists = true;
                break;
            }
        }

        if (!exists) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {

            auto [word, len] = q.front();
            q.pop();

            if (word == endWord) return len;

            for (auto &nextWord : wordList) {

                if (!visited.count(nextWord) &&
                    istrans(word, nextWord)) {

                    visited.insert(nextWord);
                    q.push({nextWord, len + 1});
                }
            }
        }

        return 0;
    }
};
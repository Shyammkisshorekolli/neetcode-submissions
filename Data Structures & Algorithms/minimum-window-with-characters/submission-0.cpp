class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return "";

        int min_idx = 0;
        int least = 0;

        vector<int> v2(128, 0);

        for (int i = 0; i < m; i++) {
            v2[t[i]]++;
        }

        for (int i = 0; i < n; i++) {

            if (v2[s[i]] == 0) continue;

            vector<int> v1(128, 0);

            int count = 0;
            int x = i;

            while (x < n) {

                if (v2[s[x]]!=0&&v1[s[x]] < v2[s[x]]) v1[s[x]]++;
                count++;
                x++;

                if (v1 == v2) break;
            }

            if (v1==v2) {
                if (least == 0 || count < least) {
                    least = count;
                    min_idx = i;
                }
            }
            else break;
        }

        if (least == 0) return "";
        cout<<least<<endl;

        return s.substr(min_idx, least);
    }
};
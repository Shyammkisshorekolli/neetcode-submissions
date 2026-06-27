class Solution {
public:
    bool dfs(string &s1, string &s2, string &s3,
             int i, int j, int k,
             int one, int two) {

        if (i == s3.size()) {
            return (j == s1.size() &&
                    k == s2.size() &&
                    abs(one - two) <= 1);
        }

        // s3 character must match at least one string
        if ((j >= s1.size() || s3[i] != s1[j]) &&
            (k >= s2.size() || s3[i] != s2[k]))
            return false;

        bool a = false, b = false;

        // Take a substring from s1
        if (j < s1.size() && s3[i] == s1[j]) {

            int x = i;
            int y = j;

            while (x < s3.size() &&
                   y < s1.size() &&
                   s3[x] == s1[y]) {
                    x++;
                    y++;}
                a = dfs(s1, s2, s3,
                        x , y , k,
                        one + 1, two);
                if (a) return true;
            
        }

        // Take a substring from s2
        if (k < s2.size() && s3[i] == s2[k]) {

            int x = i;
            int z = k;

            while (x < s3.size() &&
                   z < s2.size() &&
                   s3[x] == s2[z]) {
                    x++;
                    z++;
                   }
                b = dfs(s1, s2, s3,
                        x , j, z ,
                        one, two + 1);
                if (b) return true;
        }

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        return dfs(s1, s2, s3, 0, 0, 0, 0, 0);
    }
};
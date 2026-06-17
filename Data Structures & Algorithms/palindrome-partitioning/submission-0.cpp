class Solution {
public:
    bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }

    return true;
}
    void dfs(string s,string p,int i,vector<string>&ans,vector<vector<string>>&final){
        if(i>=s.length()) return;
        p=p+s[i];
        if(isPalindrome(p)){
            ans.push_back(p);
            if(i+1==s.length()){
                final.push_back(ans);
            }
            dfs(s,"",i+1,ans,final);
            ans.pop_back();
        }
        dfs(s,p,i+1,ans,final);
    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        vector<vector<string>>final;
        string p="";
        dfs(s,p,0,ans,final);
        return final;
    }
};

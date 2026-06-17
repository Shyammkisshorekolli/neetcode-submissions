class Solution {
public:
    void dfs(string digits,vector<string>&mp,int i,string &ans,vector<string>&final){
        if(ans.length()==digits.length()){
            final.push_back(ans);
            return;
        }
        for(auto &val:mp[digits[i]-'0']){
            ans.push_back(val);
            dfs(digits,mp,i+1,ans,final);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> mp = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        string ans="";
        vector<string>final;
        dfs(digits,mp,0,ans,final);
        return final;
    }
};
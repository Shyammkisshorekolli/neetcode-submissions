class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>maps;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            maps[temp].push_back(strs[i]);
        }
        for(auto &mp:maps){
            ans.push_back(mp.second);
        }
        return ans;
    }
};

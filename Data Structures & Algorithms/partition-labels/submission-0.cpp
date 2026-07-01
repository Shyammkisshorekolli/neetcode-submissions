class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>maps;
        for(int i=0;i<s.length();i++){
            maps[s[i]]=i;
        }
        int max_idx=-1;
        int count=0;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            max_idx=max(max_idx,maps[s[i]]);
            if(i==max_idx){
                ans.push_back(i+1-count);
                count=i+1;
            }
        }
        return ans;
    }
};

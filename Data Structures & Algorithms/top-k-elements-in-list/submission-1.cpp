class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>maps;
        vector<vector<int>>values;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            maps[nums[i]]+=1;
        }
        for(auto &mp:maps){
            values.push_back({mp.second,mp.first});
        }
        sort(values.begin(),values.end());
        int n=values.size();
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(values[i][1]);
        }
        return ans;
    }
};

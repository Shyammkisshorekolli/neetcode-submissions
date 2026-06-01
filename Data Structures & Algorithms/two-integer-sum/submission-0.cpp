class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>maps;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            maps[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int bal = target-nums[i];
            if(maps[bal]==i||maps[bal]==0) continue;
            ans.push_back(i);
            ans.push_back(maps[bal]);
            break;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>maps;
        for(int i=0;i<nums.size();i++){
            int bal=target-nums[i];
            if(maps.find(bal)!=maps.end()){
                return {maps[bal],i};
            }
            maps[nums[i]]=i;
        }
        return {};
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>sets;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sets.find(nums[i])!=sets.end()) return nums[i];
            sets.insert(nums[i]);
        }
        return -1;
    }
};

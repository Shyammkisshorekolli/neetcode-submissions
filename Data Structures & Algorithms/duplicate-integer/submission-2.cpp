class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>maps;
        int n=nums.size();
        if(n==0) return false;
        for(int i=0;i<n;i++){
            if(maps[nums[i]]==1) return true;
            else{
                maps[nums[i]]=maps[nums[i]]+1;
            }
        }
        return false;

    }
}; 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>final;
        map<vector<int>,int>map1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int target=0-nums[i];
            unordered_map<int,vector<int>>maps;
            for(int k=i+1;k<n;k++){
                int target1=target-nums[k];
                if(maps.find(target1)!=maps.end()){
                    maps[target1].push_back(nums[k]);
                    vector<int>ans;
                    ans.push_back(maps[target1][0]);
                    ans.push_back(maps[target1][1]);
                    ans.push_back(nums[i]);
                    sort(ans.begin(),ans.end());
                    map1[ans]=map1[ans]+1;
                    if(map1[ans]==1) final.push_back(ans);
                }
                if(maps[nums[k]].empty()) maps[nums[k]].push_back(nums[k]);
            }
        }
        return final;
    }
};

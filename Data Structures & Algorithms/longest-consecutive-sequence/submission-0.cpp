class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int prev=0;
        int final=0;
        unordered_map<int,int>map1;
        unordered_set<int>sets;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map1[nums[i]]=nums[i]+1;
        }
        for(int i=0;i<n;i++){
            int count=0;
            if(sets.find(nums[i])!=sets.end()) continue;
            sets.insert(nums[i]);
            count=count+1;
            int cons=map1[nums[i]];
            while(true){
                if(map1.find(cons)==map1.end()) break;
                count++;
                cons=map1[cons];
            }
            final=max(prev,count);
            prev=final;
        }
        return final;
    }
};

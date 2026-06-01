class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0;
        int product=1;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count=count+1;
            else{
                product=product*nums[i];
                continue;
            }
        }
        if(count>1){
            while(n--) ans.push_back(0);
        }
        else if(count==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0) ans.push_back(product);
                else ans.push_back(0);
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(product/nums[i]);
            }
        }
        return ans;

    }
};

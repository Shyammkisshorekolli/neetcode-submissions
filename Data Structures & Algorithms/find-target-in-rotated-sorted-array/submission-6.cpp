class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            cout<<nums[mid]<<endl;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target&&nums[mid]<nums[left]){
                if(target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
            else if(nums[mid]<target) left=mid+1;
            else if(target<nums[mid]&&nums[mid]>nums[right]){
                if(target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>pq;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            pq.insert(nums[i]);
        }
        ans.push_back(*pq.rbegin());
        for(int i=k;i<n;i++){
            pq.insert(nums[i]);
            pq.erase(pq.find(nums[i-k]));
            ans.push_back(*pq.rbegin());
        }
        return ans;
    }
};

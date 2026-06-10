class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};
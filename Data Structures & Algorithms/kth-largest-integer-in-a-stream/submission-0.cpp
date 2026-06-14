class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int x=0;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        x=k;
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()>x){
            q.pop();
        }
        return q.top();
    }
};

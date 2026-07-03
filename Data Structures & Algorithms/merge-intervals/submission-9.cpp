class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int n=intervals.size();
        bool found=false;
        if(n==1){
            ans.push_back(intervals[0]);
            return ans;
        }
        while(i<n){
            while(i+1<n&&intervals[i][1]<intervals[i+1][0]){
                ans.push_back(intervals[i]);
                i++;
            }
            if(i==n-1){
                ans.push_back(intervals[i]);
                return ans;
            }
        
            int x=min(intervals[i][0],intervals[i+1][0]);
            int y=max(intervals[i][1],intervals[i+1][1]);
            i=i+2;
        
            while(i<n&&intervals[i][0]<=y){
                x=min(intervals[i][0],x);
                y=max(intervals[i][1],y);
                i++;
            }
            ans.push_back({x,y});
        }
        return ans;
    }
};

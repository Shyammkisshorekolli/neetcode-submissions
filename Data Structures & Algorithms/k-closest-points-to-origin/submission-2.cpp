class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>q;
        int n=points.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            double x=(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            q.push({x,{points[i][0],points[i][1]}});
            if(q.size()>k) q.pop();
        }
        while(!q.empty()){
            ans.push_back({q.top().second});
            q.pop();
        }
        return ans;
    }
};

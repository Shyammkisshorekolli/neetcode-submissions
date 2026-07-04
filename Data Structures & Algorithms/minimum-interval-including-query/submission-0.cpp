class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;   // {length, right}

        vector<int> ans(queries.size(), -1);

        int i = 0;

        for(auto &[query, idx] : q){

            // Add all intervals starting before or at query
            while(i < intervals.size() && intervals[i][0] <= query){
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }

            // Remove intervals that end before query
            while(!pq.empty() && pq.top().second < query)
                pq.pop();

            if(!pq.empty())
                ans[idx] = pq.top().first;
        }

        return ans;
    }
};
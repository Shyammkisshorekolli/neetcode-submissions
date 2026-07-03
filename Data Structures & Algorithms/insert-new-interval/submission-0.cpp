class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int a = newInterval[0];
        int b = newInterval[1];
        int count = 0;

        for (int i = 0; i < n; i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];

            if (y < a || x > b)
                ans.push_back({x, y});
            else {
                if (count != 0) ans.pop_back();
                ans.push_back({min(a, x), max(b, y)});
                a = min(a, x);
                b = max(b, y);
                count++;
            }
        }

        // No overlap occurred
        if (count == 0) {
            ans.clear();
            bool inserted = false;

            for (auto &it : intervals) {
                if (!inserted && newInterval[0] < it[0]) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(it);
            }

            if (!inserted)
                ans.push_back(newInterval);
        }

        return ans;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.start < b.start;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &meeting : intervals) {

            if (!pq.empty() && meeting.start >= pq.top())
                pq.pop();          

            pq.push(meeting.end);  
        }

        return pq.size();
    }
};
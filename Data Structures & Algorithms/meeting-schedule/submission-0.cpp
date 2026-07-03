/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int prev=0;
        sort(intervals.begin(),intervals.end(),[](const Interval&a,const Interval&b){
            if(a.start==b.start) return a.end<b.end;
            return a.start<b.start;
        });
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<intervals[prev].end) return false;
            prev=i;
        }
        return true;
    }
};

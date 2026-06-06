class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,double>>value;
        for(int i=0;i<n;i++){
            double time=(double) (target-position[i])/speed[i];
            value.push_back({position[i],time});
        }
        sort(value.begin(),value.end());
        double maxtime=0;
        int fleets=0;
        for(int i=n-1;i>=0;i--){
            if(value[i].second>maxtime){
                fleets++;
                maxtime=value[i].second;
            }
        }
        return fleets;
    }
};

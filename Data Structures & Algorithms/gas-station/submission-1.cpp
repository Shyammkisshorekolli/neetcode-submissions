class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        int count=0;
        int gas_=0;
        for(int i=0;i<gas.size();i++){
            if(count==n) return i-n;
            if(gas_+gas[i]<cost[i]){
                count=0;
                gas_=0;
                continue;
            }
            count++;
            gas_=gas_+gas[i]-cost[i];
        }
        return -1;
    }
};

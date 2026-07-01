class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int count = 0;
        int gas_ = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (count == n)
                return i - n;

            if (gas_ + gas[i % n] < cost[i % n]) {
                count = 0;
                gas_ = 0;
                continue;
            }

            count++;
            gas_ += gas[i % n] - cost[i % n];
        }

        return -1;
    }
};
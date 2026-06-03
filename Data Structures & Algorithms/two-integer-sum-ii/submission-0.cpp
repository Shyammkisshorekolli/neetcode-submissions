class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,vector<int>>map1;
        int n=numbers.size();
        for(int i=0;i<n;i++){
            vector<int>ans;
            int bal=target-numbers[i];
            if(map1.find(bal)!=map1.end()){
                map1[bal].push_back(i+1);
                return map1[bal];
            }
            map1[numbers[i]].push_back(i+1);
        }
        return {};
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int res=0;
            for(int j=0;j<32;j++){
                if(1<<j&i) res++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};

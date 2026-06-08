class Solution {
public:
bool caneat(vector<int>& piles,int h,int k){
    long long hours=0;
    for(int i=0;i<piles.size();i++){
        hours=hours+(piles[i]+k-1)/k;
    }
    return hours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int ans=0;
        int m=*max_element(piles.begin(),piles.end());
        int left=1;
        int right=m;
        while(left<=right){
            int mid=(left+right)/2;
            if(caneat(piles,h,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};

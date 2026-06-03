class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int area=0;
        int left=0;
        int right=n-1;
        while(left<right){
            int currentArea=min(heights[left],heights[right])*(right-left);
            area=max(area, currentArea);
            if(heights[left]<heights[right]){
                left=left+1;
            }
            else{
                right=right-1;
            }
        }
        return area;
    }
};
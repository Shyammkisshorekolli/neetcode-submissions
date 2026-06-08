class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        cout<<m<<n<<endl;
        int left=0;
        int right=m-1;
        int mid=0;
        int x=0;
        while(left<=right){
            mid=(left+right)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target) left=mid+1;
            else right=mid-1;
        }
        if(matrix[mid][0]<target) x=left-1;
        else x=right;
        int left_=0;
        int right_=n-1;
        while(left_<=right_&&x>=0){
            mid=(left_+right_)/2;
            if(matrix[x][mid]==target) return true;
            else if(matrix[x][mid]<target) left_=mid+1;
            else if(matrix[x][mid]>target) right_=mid-1;
        }
        return false;
    }
};

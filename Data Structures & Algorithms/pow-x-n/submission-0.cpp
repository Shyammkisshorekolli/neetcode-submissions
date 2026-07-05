class Solution {
public:
    double myPow(double x, int n) {
        double y=1;
        int count=0;
        if(n==0) return 1;
        if(n<0){
            x=1/x;
            while(count<abs(n)){
                y=x*y;
                count++;
            }
            return y;
        }
        while(count<n){
            y=x*y;
            count++;
        }
        return y;
    }
};

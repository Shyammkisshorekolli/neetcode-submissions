class Solution {
public:
    bool isHappy(int n) {
        if(n==1000) return true;
        unordered_set<int>sets;
        while(true){
            sets.insert(n);
            int a=n/100;
            int b=(n/10)%10;
            int c=(n%10);
            n=a*a+b*b+c*c;
            if(n==1) return true;
            if(sets.find(n)!=sets.end()) return false;
        }
        return false;
    }
};

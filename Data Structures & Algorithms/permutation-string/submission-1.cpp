class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        sort(s1.begin(),s1.end());
        if(m>n) return false;
        for(int i=0;i<=n-m;i++){
            string s="";
            for(int k=i;k<i+m;k++){
                s=s+s2[k];
            }
            sort(s.begin(),s.end());
            if(s==s1) return true;
        }
        return false;
    }
};

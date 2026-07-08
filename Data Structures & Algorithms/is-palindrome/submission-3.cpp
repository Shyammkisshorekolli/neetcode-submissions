class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        unordered_set<char>set1;
        unordered_set<char>set2;
        set1.insert({'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'});
        set2.insert({'1','2','3','4','5','6','7','8','9','0'});
        int n=s.length();
        string str="";
        string str1="";
        for(int i=0;i<n;i++){
            if(set1.find(s[i])==set1.end()&&set2.find(s[i])==set2.end()) continue;
            str=str+s[i];
            str1=s[i]+str1;
        }
        cout<<str<<endl;
        cout<<str1<<endl;
        if(str==str1) return true;
        else return false;
    }
};

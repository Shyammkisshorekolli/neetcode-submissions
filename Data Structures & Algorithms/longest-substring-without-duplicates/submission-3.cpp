class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0;
        int count=0;
        int n=s.size();
        int x=0;
        unordered_map<char,int>maps;
        for(int i=0;i<n;i++){
            if(maps.find(s[i])!=maps.end()&&(!(maps[s[i]]<x))){
                longest=max(count,longest);
                x=maps[s[i]];
                count=i-maps[s[i]];
                maps[s[i]]=i;
            }
            else{
                maps[s[i]]=i;
                count=count+1;
            }
        }
        return max(count,longest);
    }
};

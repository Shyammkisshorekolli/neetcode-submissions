class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> maps;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        maps[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(maps.find(key)==maps.end()||maps[key].size()==0) return "";
        int n=maps[key].size();
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=(left+right)/2;
            if(maps[key][mid].first==timestamp) return maps[key][mid].second;
            else if(maps[key][mid].first<timestamp) left=mid+1;
            else right=mid-1;
        }
        if(maps[key][left].first==timestamp) return maps[key][left].second;
        else if(maps[key][left].first>timestamp and left==0) return "";
        else if(maps[key][left].first>timestamp) return maps[key][left-1].second;
        else return maps[key][left].second;
    }
};

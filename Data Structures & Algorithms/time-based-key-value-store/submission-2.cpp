class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> maps;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        maps[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {


        if(maps.find(key) == maps.end() || maps[key].size() == 0)
        return "";

        auto &v = maps[key];

        int left = 0;
        int right = v.size() - 1;

        int ans = -1;

        while(left <= right) {

            int mid = (left + right) / 2;

            if(v[mid].first == timestamp)
            return v[mid].second;

            else if(v[mid].first < timestamp) {
                ans = mid;
                left = mid + 1;
        }
            else {
                right = mid - 1;
        }
    }

        if(ans == -1)
            return "";

        return v[ans].second;
}
};
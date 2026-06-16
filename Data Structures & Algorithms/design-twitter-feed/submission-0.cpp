class Twitter {
    int timer = 0;

    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, vector<pair<int,int>>> tweets;
    // {timestamp, tweetId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;
        vector<int> ans;

        following[userId].insert(userId);

        for(auto user : following[userId]) {

            auto &t = tweets[user];

            if(!t.empty()) {

                int idx = t.size() - 1;

                pq.push({
                    t[idx].first,
                    t[idx].second,
                    user,
                    idx
                });
            }
        }

        while(!pq.empty() && ans.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            if(idx > 0) {

                idx--;

                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
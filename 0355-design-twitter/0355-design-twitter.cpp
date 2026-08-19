class Twitter {
private:
    int timeStamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> allTweets;

        for (auto &tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }
        for (int followee : following[userId]) {
            for (auto &tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }
        sort(allTweets.begin(), allTweets.end(), greater<pair<int, int>>());
        vector<int> res;
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            res.push_back(allTweets[i].second);
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
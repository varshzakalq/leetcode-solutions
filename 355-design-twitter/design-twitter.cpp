
class Twitter {
public:
class user{
public:
    unordered_set<int> followers;
    unordered_set<int> following;
};

    unordered_map <int,user> mp;
    vector<pair<int, int>> globalTweets;
    Twitter() {
        
    }
   

    void postTweet(int userId, int tweetId) {
        globalTweets.push_back({userId,tweetId});    
    }
    
    vector<int> getNewsFeed(int userId) {
        vector <int> feed;
        int i=globalTweets.size()-1;
        int count = 0; 
        const auto& following = mp[userId].following;
        while(i>=0&& count <10){
            if(globalTweets[i].first == userId || following.find(globalTweets[i].first) !=following.end() ){
                feed.push_back(globalTweets[i].second);
                count++;
            }
            i--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        if(mp[followerId].following.find(followeeId) == mp[followerId].following.end()){
            mp[followerId].following.insert(followeeId);
            mp[followeeId].followers.insert(followerId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        if(mp[followerId].following.find(followeeId) != mp[followerId].following.end()){
            mp[followerId].following.erase(followeeId);
            mp[followeeId].followers.erase(followerId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
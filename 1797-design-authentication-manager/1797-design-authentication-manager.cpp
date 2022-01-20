class AuthenticationManager {
public:
    int time = 0;
    unordered_map<string, int>hash;
    AuthenticationManager(int timeToLive) {
        time = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        hash[tokenId] = currentTime + time;
    }
    
    void renew(string tokenId, int currentTime) {
        if(hash.count(tokenId) and hash[tokenId]>currentTime){
            hash[tokenId] = currentTime + time;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto x : hash){
            if(x.second > currentTime){
                cnt++;
            }
        }
        return cnt;
    }
};

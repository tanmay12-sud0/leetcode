class Solution {
public:
    
    unordered_map<string, string>hash;
    int num = 0;
    
    string encode(string longUrl) {
        num++;
        string ans = "http://tinyurl.com/";
        ans += to_string(num);
        hash[ans] = longUrl;
        return ans;
    }

    string decode(string shortUrl) {
        return hash[shortUrl];
    }
};

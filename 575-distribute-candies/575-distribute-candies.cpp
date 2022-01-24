class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_map<int, int>hash;
        for(int i=0; i<candy.size(); i++){
            hash[candy[i]]++;
        }
        if(hash.size()>(candy.size()/2)){
            return (candy.size()/2);
        }
        return hash.size();
    }
};
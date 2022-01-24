class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<string, int>hash;
        hash["00"]++;
        int x=0, y=0;
        for(int i=0; i<path.size(); i++){
            if(path[i] == 'N'){
                y++;
                if(hash.count(to_string(x)+to_string(y))){
                    return true;
                }
                hash[to_string(x)+to_string(y)]++;
            }
            if(path[i] == 'E'){
                x++;
                if(hash.count(to_string(x)+to_string(y))){
                    return true;
                }
                hash[to_string(x)+to_string(y)]++;
            }
            if(path[i] == 'S'){
                y--;
                if(hash.count(to_string(x)+to_string(y))){
                    return true;
                }
                hash[to_string(x)+to_string(y)]++;
            }
            if(path[i] == 'W'){
                x--;
                if(hash.count(to_string(x)+to_string(y))){
                    return true;
                }
                hash[to_string(x)+to_string(y)]++;
            }
        }
        return false;
    }
};
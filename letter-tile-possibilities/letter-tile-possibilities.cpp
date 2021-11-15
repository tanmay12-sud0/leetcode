class Solution {
public:
    int count;
     unordered_set<string>s;
    void backTrack(string tile, int n, int i){
        
        for(int k=i; k<n; k++){
            swap(tile[i], tile[k]);
            s.insert(tile.substr(0, i+ 1)); 
            backTrack(tile, n, i+1);
            swap(tile[i], tile[k]);

        }
        return;
    }
    int numTilePossibilities(string tiles) {
       
        backTrack(tiles,tiles.length(),0);
        return s.size();
    }
};
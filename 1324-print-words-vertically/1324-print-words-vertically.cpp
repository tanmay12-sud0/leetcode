class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>umap;
        vector<string>uumap;
        int len = s.length();
        int max_len_word = 0;
        stringstream ss(s);
        string word;
        
        while(ss >> word){
            if(max_len_word < word.length()){
                max_len_word = word.length();
            }
            umap.push_back(word);
        }
        
        map<int, string>hash;
        for(int i=0; i<umap.size(); i++){
            for(int j=0; j<max_len_word; j++){
                if(umap[i].length()>j){
                    hash[j] += umap[i][j];
                }else{
                    hash[j] += " ";
                }
            }
            
        }
        for(auto x : hash){
            cout << x.first << ", ,," << x.second << endl;
            while(x.second.back()==' '){
                auto it = x.second.end();
                it--;
                x.second.erase(it);
            }
            uumap.push_back(x.second);
        }
        
        return uumap;
    }
};
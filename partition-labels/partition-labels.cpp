class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>umap;
        unordered_map<char, int>hash;
        int len = s.length();
        for(int i=0; i<len; i++){
            hash[s[i]] = i;
        }
        int x = 0;
        int value = 0;
        while(value<len){
            value = hash[s[value]];
            for(int i=0; i<=value and i<len; i++){
                if(hash[s[i]] > value){
                    value = hash[s[i]];
                }
            }
            cout << value << endl;
            if(umap.size()){
                umap.push_back(value-x+1);
            }else{
                umap.push_back(value+1);
            }
            
            value++;
            x = value;
        }
        return umap;
    }
};
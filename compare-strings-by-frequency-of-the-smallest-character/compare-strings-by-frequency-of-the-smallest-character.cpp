class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int>hash;
        vector<int>qhash;
        vector<int>new_hash;
        for(int i=0; i<n; i++){
            string x = words[i];
            vector<int>umap(27, 0);
            for(int j=0; x[j] != '\0'; j++){
                umap[x[j]-'a']++;
            }
            for(int j=0; j<26; j++){
                if(umap[j]!=0){
                    hash.push_back(umap[j]);
                    break;
                }
            }
        }
        sort(hash.begin(), hash.end());
        int m = queries.size();
        for(int i=0; i<m; i++){
            string x = queries[i];
            vector<int>umap(27, 0);
            for(int j=0; x[j] != '\0'; j++){
                umap[x[j]-'a']++;
            }
            for(int j=0; j<26; j++){
                if(umap[j]!=0){
                    qhash.push_back(umap[j]);
                    break;
                }
            }
        }
        for(int i=0; i<qhash.size(); i++){
            int x = hash.end() - upper_bound(hash.begin(), hash.end(), qhash[i]);
            new_hash.push_back(x);
        }
        return new_hash;
    }
};
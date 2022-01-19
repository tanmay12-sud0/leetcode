bool compare(int a, int b){
    return a>b;
}

class Solution {
public:
    
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>umap;
        unordered_map<int, int>hash;
        if(changed.size()%2!=0){
            return umap;
        }
        sort(changed.begin(), changed.end(), compare);
        for(int i=0; i<changed.size(); i++){
            if(hash.count(2*changed[i])){
                umap.push_back(changed[i]);
                hash[2*changed[i]]--;
                if(hash[2*changed[i]] == 0){
                    hash.erase(2*changed[i]);
                }
            }else{
                hash[changed[i]]++;
            }
        }
        if(umap.size() == changed.size()/2){
            return umap;
        }
        umap.clear();
        return umap;
    }
};
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>umap;
        unordered_map<string, int>hash;
        for(int i=0; i<list1.size(); i++){
            hash[list1[i]] = i;
        }
        int min_sum = INT_MAX;
        for(int i=0; i<list2.size(); i++){
            if(hash.count(list2[i])){
                min_sum = min(min_sum, i+hash[list2[i]]);
            }
        }
        for(int i=0; i<list2.size(); i++){
            if(hash.count(list2[i]) and i+hash[list2[i]]==min_sum){
                umap.push_back(list2[i]);
            }
        }
        return umap;
    }
};
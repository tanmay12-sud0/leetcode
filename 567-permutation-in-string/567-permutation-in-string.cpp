class Solution {
public:
    
    bool isPossible(vector<int>umap1, vector<int>umap2){
        for(int i=0; i<27; i++){
            if(umap2[i] < umap1[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int>umap1(27, 0);
        vector<int>umap2(27, 0);
        for(auto x : s1){
            umap1[x-'a']++;
        }
        int left = 0;
        int right = 0;
        while(right < s2.length()){
            umap2[s2[right]-'a']++;
            while(isPossible(umap1, umap2) and left <= right){
                if(right-left == s1.length()-1){
                    cout << left << ", " << right << endl;
                    return true;
                }
                umap2[s2[left]-'a']--;
                left++;
            }
            right++;           
        }
        return false;
    }
};
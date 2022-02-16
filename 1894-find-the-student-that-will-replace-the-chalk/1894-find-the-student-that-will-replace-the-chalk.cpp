class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long int>umap;
        umap.push_back(chalk[0]);
        for(int i=1; i<n; i++){
            umap.push_back(chalk[i] + umap.back());
        }
        int value = k%umap[n-1];
        cout << value << endl;
        auto it = upper_bound(umap.begin(), umap.end(), value)- umap.begin();
        return it;
    }
};
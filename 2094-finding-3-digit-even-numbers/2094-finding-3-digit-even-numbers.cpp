class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int>hash;
        for(int i=0; i<digits.size(); i++){
            hash[digits[i]]++;
        }
        vector<int>umap;
        for(int i=100; i<1000; i+=2){
            int a = (i/1)%10;
            int b = (i/10)%10;
            int c = (i/100)%10;
            map<int, int>hash2;
            hash2[a]++;
            hash2[b]++;
            hash2[c]++;
            cout << a << ", " << b <<", " << c << endl;
            if(hash.count(a) and hash[a]>=hash2[a] and hash.count(b) and hash[b]>=hash2[b] and hash.count(c) and hash[c]>=hash2[c]){
                umap.push_back(i);
            }
        }
        return umap;
    }
};
class Solution {
public:
    
    int fact(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 

    
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>hash(rowIndex+1);
        for(int i=0; i<=rowIndex; i++){
            hash[i].resize(i+1);
            hash[i][0] = hash[i][i] = 1;
            for(int x=1; x<i; x++){
                hash[i][x] = hash[i-1][x-1] + hash[i-1][x];
            }
        }
        return hash[rowIndex];
    }
};
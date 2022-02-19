class Solution {
public:
    vector<int>umap;
    void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
  
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
  
    for (int p=2; p<=n; p++)
       if (prime[p])
          umap.push_back(p);
}
    
    
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int>hash;
        int n = deck.size();
        SieveOfEratosthenes(n);
        for(int i=0; i<n; i++){
            hash[deck[i]]++;
        }
        int cnt = 0;
        int index;
        bool f = false;
        for(int i=0; i<umap.size(); i++){
            cnt = 0;
            for(auto x : hash){
                if(x.second%umap[i] != 0){
                    break;
                }else{
                    cnt++;
                }
            }
            if(cnt == hash.size()){
                index = i;
                f = true;
                break;
            }
        }
        if(!f){
            return 0;
        }
        
        return 1;
    }
};
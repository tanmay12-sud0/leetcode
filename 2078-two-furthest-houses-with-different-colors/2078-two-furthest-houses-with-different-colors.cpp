class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int check = colors[0];
        int nn,m;
        for(int i=n-1; i>=0;){
            if(colors[i] == check){
                i--;
            }else{
                nn =  abs(i-0);
                break;
            }
        }
        int ch = colors[n-1];
        for(int i=0; i<n;){
            if(colors[i] == ch){
                i++;
            }else{
               m = abs(n-1-i);
                break;
            }
        }
        return max(nn, m);
    }
};
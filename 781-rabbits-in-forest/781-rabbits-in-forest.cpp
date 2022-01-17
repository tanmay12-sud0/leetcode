class Solution {
public:
    int numRabbits(vector<int>& answer) {
        unordered_map<int, int>hash;
        int cnt = 0;
        for(int i=0; i<answer.size(); i++){
            hash[answer[i]]++;
        }
        for(auto x : hash){
            if(x.first == 0){
                cnt += x.second;
                continue;
            }
            if(x.second <= x.first+1){
                cnt += x.first+1;
            }else{
                float a = (float(x.second)/float(x.first+1));
                cout << a << endl;
                cnt += ceil(a)*(x.first+1);
            }
        }
        return cnt;
    }
};
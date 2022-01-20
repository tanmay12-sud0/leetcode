class FreqStack {
public:
   unordered_map<int,int>mp;
    unordered_map<int,vector<int>>hash;
    int mx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int cnt=++mp[val];
        hash[cnt].push_back(val);
        mx=max(mx,cnt);
    }
    
    int pop() {
        int ans=hash[mx].back();
        hash[mx].pop_back();
        mp[ans]--;
        if(hash[mx].size()==0){
            hash.erase(mx);
            mx--;
        }
        return ans;
    }
};






// class FreqStack {
// public:
//     unordered_map<int, pair<int, vector<int>>>hash;
//     int cnt = 0;
//     FreqStack() {
        
//     }
//     void push(int val) {
//         if(hash.count(val)){
//             pair<int, vector<int>>x = hash[val];
//             x.first++;
//             x.second.push_back(++cnt);
//             hash[val] = x;
//             return;
//         }else{
//             pair<int, vector<int>>x;
//             x.first = 1;
//             x.second.push_back(++cnt);
//             hash[val] = x;
//         }
//         return;
//     }
    
//     int pop() {
        
//         int maxValue = 0;
//         int maxSecond = 0;
//         int value = 0;
//         for(auto x : hash){
//                 if(x.second.first >= maxValue){
//                     maxValue = x.second.first;
//                 }
//         }
//         for(auto x : hash){
//             if(x.second.first == maxValue){
//                 if(x.second.second.back() > maxSecond){
//                     maxSecond = x.second.second.back();
//                     value = x.first;
//                  }
//             }
//         }
//         auto x = hash[value];
//         x.first--;
//         x.second.pop_back();
//         if(x.first == 0){
//             hash.erase(value);
//         }else{
//             hash[value] = x;
//         }
//         return value;
//     }
// };

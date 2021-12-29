class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int>cnt(26,0);
        for(int i=0;i<n;i++)
            cnt[s[i]-'a']++;
        vector<bool>vis(26,false);
        string ans="";
        for(int i=0;i<n;i++){
            if(vis[s[i]-'a']){
                cnt[s[i]-'a']--;
                continue;
            }
            while(!ans.empty() && s[i] < ans.back() && cnt[ans.back()-'a']>0){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]-'a']=true;
            cnt[s[i]-'a']--;
        }
        return ans;
//         int n = s.length();
//         vector<int>umap(26, -1);
//         for(int i=0; i<n; i++){
//             umap[s[i]-'a'] = i;
//         }
//         stack<int>ss;
//         unordered_set<char>hash;
        
//         for(int i=0; i<umap.size(); i++){
//             cout << char(i+'a') <<", "<< umap[i] << endl;
//         }
        
//         for(int i=0; i<n; i++){
//             if(ss.empty()){
//                 ss.push(i);
//                 hash.insert(s[i]);
//                 continue;
//             }
//         while(!ss.empty() and s[ss.top()] > s[i] and ss.top()<umap[s[ss.top()]-'a']){
//             hash.erase(s[ss.top()]);
//             ss.pop();
//         }
//         if(!hash.count(s[i])){
//             hash.insert(s[i]);
//             ss.push(i);
//             }
//         }
        
//         string pp;
//         while(!ss.empty()){
//             pp += s[ss.top()];
//             ss.pop();
//         }
//         reverse(pp.begin(), pp.end());
//         return pp;
    }
};
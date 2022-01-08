class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]!='0')return false;
        // if(s[0]!='0')return false;
        queue<int>q;
        q.push(0);
        int curr_max = 0;
        int i =0;
        while(!q.empty()){
            i = q.front();
            q.pop();
            if(i == n-1){
                return true;
            }
            
            for(int j=max(curr_max, i+minJump); j<= min(i+maxJump, n-1); j++){
                if(s[j] == '0'){
                    q.push(j);
                }
            }
            curr_max = min(i+maxJump+1, n);
        }
        return false;
    }
};


















//         int n = s.length();
//         vector<bool>visited(n, false);
//         int left = 0;
//         int right = maxJump-minJump;
//         int reach = 0;
//         for(int i=left; i<=right; i++){
//             if(s[i]=='0'){
//                 visited[i] = true;
//                 reach++;
//             }
//         }
//         cout << "reach" << reach << endl;
//         while(right < n){
//              if(s[++right]=='0'){
//                  reach++;
//              }         
//             if(s[left++] == '0'){
//                 reach--;
//             }
//             if(reach>0 and s[right]=='0'){
//                 visited[right] = true;
//             }
//         }
//         for(auto x : visited){
//             cout << x << ", ";
//         }
        
//         return visited[n-1];

// if(s[0] == '0'){
//             visited[0] = true;
//         }
//         for(int i=1; i<n; i++){
//             if(s[i]=='0'){
//                 int x = i-maxJump>=0 ? i-maxJump : 0;
//                 int y = i-minJump>=0 ? i-minJump : 0;
//                 for(int a=x; a<=y; a++){
//                     if(visited[a]==true){
//                         visited[i] = true;
//                         break;
//                     }
//                 }
//             }
//         }
//         for(auto x : visited){
//             cout << x << ", ";
//         }
//         return visited[n-1];
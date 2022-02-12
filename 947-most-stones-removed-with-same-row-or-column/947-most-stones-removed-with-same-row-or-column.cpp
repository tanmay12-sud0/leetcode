class Solution {
public:
    int cnt;
    vector<int>visited;
    void dfs(vector<vector<int>>&stones,int index){
        visited[index]=true;
        cnt++;
        for(int i=0;i<stones.size();i++){
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                dfs(stones,i);
        }
    }
    int removeStones(vector<vector<int>>&stones) {
        visited.resize(stones.size(),0);
        int result=0;
        for(int i=0;i<stones.size();i++){
            if(visited[i]){
                continue;
            }cnt=0;
            dfs(stones,i);
            cout<<cnt<<" ";
                result+=cnt-1;
            
        }
        return result;
    }
};
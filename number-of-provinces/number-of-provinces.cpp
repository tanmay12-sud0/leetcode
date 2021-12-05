class Solution {
public:
    
    class Graph{
public:
  int v;
  vector<int>*l;

  Graph(int n){
    v = n;
    l = new vector<int>[n];
  }

  void addEdge(int x, int y){
    l[x].push_back(y);
    l[y].push_back(x);
  }


  void dfs(vector<int>&visited, int source){
        visited[source] = true;
        for(auto nbr : l[source]){
            if(!visited[nbr]){
                dfs(visited, nbr);
            }
        }  
        return;
    }
    int dfsHeaper(){
        vector<int>visited(v, 0);
        int count = 0;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                dfs(visited, i);
                count++;
            }
        }
        return count;
    }

};

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Graph g(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isConnected[i][j] == 1){
                cout << i << ", " << j << endl;
                g.addEdge(i, j);
            }
        }
    }
    return g.dfsHeaper();
    }
};
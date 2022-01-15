class Solution {
public:
    
    class graph
{
  vector<int>*adjacency_list; 
  int Vertices;
  public:
    
    graph(int n)
    {
      Vertices=n;
      adjacency_list=new vector<int>[Vertices]; 
    }
  
    void add_edge( int u,int v )
   { 
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
    
   }

    void dfss(int node, vector<bool>&visiteded, vector<int>&stacks){
        visiteded[node] = true;
        stacks.push_back(node);
        for(auto nbr : adjacency_list[node]){
            if(visiteded[nbr] == false){
                dfss(nbr, visiteded, stacks);
            }
        }
        return;
    }

};

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        graph g(n+1);
        vector<bool>visiteded(n+1, false);
        vector<int>stacks;
        unordered_map<int, int>hash;
        unordered_map<int, int>hash2;
        unordered_map<int, int>hash3;
        for(int i=0; i<n; i++){
            hash[adjacentPairs[i][0]]++;
            hash[adjacentPairs[i][1]]++;
        }
        
        int count = 0;
       for(auto x : hash){
           hash2[x.first] = count;
           hash3[count] = x.first;
           count++;
       }
        
        for(int i=0; i<n; i++){
            g.add_edge(hash2[adjacentPairs[i][0]], hash2[adjacentPairs[i][1]]);
        }
        
        for(auto x : hash){
            if(x.second==1){
                g.dfss(hash2[x.first], visiteded, stacks);
                break;
            }
        }
        for(int i=0; i<stacks.size(); i++){
            stacks[i] = hash3[stacks[i]];
        }
        return stacks;
    }
};
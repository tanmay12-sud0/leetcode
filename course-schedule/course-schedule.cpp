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
    
   }
    


    bool dfss(int node, vector<bool>&stacks, vector<bool>&visiteded){
        visiteded[node] = true;
        stacks[node] = true;

        for(auto nbr : adjacency_list[node]){
            if(stacks[nbr] == true){
                return true;
            }
            else if(visiteded[nbr] == false){
                bool isfound = dfss(nbr, stacks , visiteded);
                if(isfound){
                    return true;
                }
            }
        }
        stacks[node] = false;
        return false;
    }

    bool cyclehelper(){
        
        vector<bool>visiteded(Vertices, false);
        vector<bool>stacks(Vertices, false);
        for(int i=0; i<Vertices; i++){
            if(!visiteded[i]){
                if(dfss(i, stacks, visiteded)){
                return true;
                }
            }
        }
    return false;
    }
    
};
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        // bool visited[100000]={0};
        for(int i=0; i<prerequisites.size(); i++){
            g.add_edge(prerequisites[i][0], prerequisites[i][1]);
        }
        return !g.cyclehelper();

    }
};
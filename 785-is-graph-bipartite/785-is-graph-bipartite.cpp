class Solution {
public:
    
    class Graph{
public:
	int v;
	list<int>*l;

	Graph(int n){
		v = n;
		l = new list<int>[v];
			}

	void addEdge(int x, int y, bool undir = true){
	l[x].push_back(y);
	
	if(undir){
		l[y].push_back(x);
	}
		return;
	}



	bool bipartite_graph(int node, vector<int>&visited, int parent, int color){
		visited[node] = color;
        
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool tan = bipartite_graph(nbr, visited, node, 3-color);
                if(!tan){
                    return false; 
                }
            }else if(node != parent and color == visited[nbr]){
                return false;
            }
        }
        return true;
	}


	bool check_bipartite_graph(int node){
		vector<int>visited(v,0);
		int parent = -1;
        
        for(int i=0;i<v;i++){
             if(visited[i]==0 && bipartite_graph(i,visited,-1,1)==false){ 
	                return false;
	            }
        }
        return 1;
	}


};
  
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        Graph g(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                g.addEdge(i, graph[i][j]);
            }
        }
        return (g.check_bipartite_graph(0));
        
    }
};
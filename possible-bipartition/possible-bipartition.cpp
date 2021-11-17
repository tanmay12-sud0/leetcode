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
				bool tanmay = bipartite_graph(nbr, visited, node, 3-color);
				if(!tanmay){
					return false;
				}
			}else if(nbr != parent && color == visited[nbr]){
				return false;
			}
		}
		return true;
	}


	bool check_bipartite_graph(int node){
		vector<int>visited(v,0);
		int parent = -1;
        // if(!l[node].front()){
        //     return false;
        // }
        for(int i=0;i<v;i++){
             if(visited[i]==0 && bipartite_graph(i,visited,-1,1)==false){ 
	                return false;
	            }
        }
        return 1;
	}


};
    
    
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        Graph g(n);
        int len = dislikes.size();
        for(int i=0; i<len; i++){
            g.addEdge(dislikes[i][0]-1, dislikes[i][1]-1);
        }
        return (g.check_bipartite_graph(0));
    }
};




class Solution {
public:
    
    class Graph{

	int v;
	list<int>*l;

public:
	
	Graph(int n){
		v = n;
		l = new list<int>[v];
	}

	void addEdge(int x, int y, bool undir = false){
		l[x].push_back(y);
		if(undir){
			l[y].push_back(x);
		}
		return;
	}


	void bfs(int source){
		vector<bool>visited(v, false);
		queue<int>q;
		visited[source] = true;
		q.push(source);

		while(!q.empty()){
			int f = q.front();
			cout << f <<", ";
			q.pop();
			for(auto x : l[f]){
				if(!visited[x]){
					q.push(x);
					visited[x] = true;
				}
			}
		}
		return;
	}


	int minbfs(int source, int dest){
		vector<bool>visited(v, false);
		vector<int>dist(v, 0);
		vector<int>parent(v, -1);

		queue<int>q;
		visited[source] = true;
		q.push(source);
		dist[source] = 0;
		parent[source] = -1;

		while(!q.empty()){
			int f = q.front();

			// cout << f <<", ";
			q.pop();

			for(auto x : l[f]){
				if(!visited[x]){
					q.push(x);
					visited[x] = true;
					parent[x] = f;
					dist[x] = dist[f] + 1;
				}
			}
		}
		for(int i=0; i<v; i++){
			cout << dist[i] << " ,";
		}
		cout << endl;
		return dist[dest];
	}

	void dfsHealper(int source, vector<bool>&visited){
		visited[source] = true;
		cout << source << " ,";
		for(auto nbr : l[source]){
			if(!visited[nbr]){
				dfsHealper(nbr, visited);
			}
		}
		return;
	}

	void dfs(int source){
		vector<bool>visited(v, false);
		dfsHealper(source, visited);
	}

	void print(){
		for(int i=0; i<v; i++){
			cout << i << ", ";
			
			for(auto x : l[i]){
				cout << x << "-->";
				
			}
			cout << endl;
		}
		return;
	}
	bool undirected_cycle(vector<bool>&visited, int source, int parent){
		visited[source] = true;

		for(auto nbr : l[source]){
			if(!visited[nbr]){
				bool subprob = undirected_cycle(visited, nbr, source);
				if(subprob){
					return true;
				}
			}else if(parent != nbr){
				return true;
			}
		}
		return false;
	}

	bool undirected_cycle_detection(int source){
		vector<bool>visited(v+1, 0);
		return undirected_cycle(visited, 0, -1);
	}


	bool directed_graph(vector<bool>&stack, vector<bool>&visited, int source){
		stack[source] = true;
		visited[source] = true;

		for(auto nbr : l[source]){
			if(stack[nbr]){
				return true;
			}
			else if(!visited[nbr]){
				bool subprob = directed_graph(stack, visited, nbr);
				if(subprob){
					return true;
				}
			}
		}
		stack[source] = false;
		return false;
	}

	bool directed_healper(int source){
		vector<bool>visited(v,0);
		vector<bool>stack(v, 0);
		return directed_graph(stack, visited, source);
	}


	bool bipartite(int source, vector<bool>&visited, int parent, int color){
		visited[source] = color;

		for(auto nbr : l[source]){
			if(!visited[nbr]){
				bool subprob = bipartite(nbr, visited, source, 3-color);
				if(!subprob){
					return false;
				}
			}else if(parent != nbr and color == visited[nbr]){
				return false;
			}
		}
		return true;
	}


	bool bipartite_helper(int source){
		vector<bool>visited(v, 0);
		int parent = -1;
		int color = 1;
		return bipartite(source, visited, parent, color);
	}

	// khans algo
	void topological_sort(){
		vector<int>indegree(v, 0);
		for(int i=0; i<v; i++){
			for(auto x : l[i]){
				indegree[x]++;
			}
		}

		queue<int>q;

		for(int i=0; i<v; i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int f = q.front();
			q.pop();
			cout << f << ", ";
			for(auto nbr : l[f]){
				indegree[nbr]--;
				if(indegree[nbr]==0){
					q.push(nbr);
				}
			}
		}
		return;
	}
    
    void dfss(int source, vector<bool>visited, int n, vector<vector<int>>&hash, vector<int>& old_hash){

    	// visited[source] = true;
    	old_hash.push_back(source);

    	if(source == n-1){
    		hash.push_back(old_hash);
    	}
    	for(auto nbr : l[source]){
    		dfss(nbr, visited, n, hash, old_hash);
    	}
    	old_hash.pop_back();
    	return;
    }
};
    

    
 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        Graph g(n);
        for(int i=0; i<n; i++){
        	for(int j=0; j<graph[i].size(); j++){
        		g.addEdge(i, graph[i][j]);
        	}
        }
        vector<bool>visited(n,0);
        vector<vector<int>>hash;
        vector<int>old_hash;
        g.dfss(0, visited, n, hash ,old_hash);

        return hash;
    }
};
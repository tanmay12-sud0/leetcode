

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

	void addEdge(int x, int y, bool undir = false){
	l[x].push_back(y);
	
	if(undir){
		l[y].push_back(x);
	}
		return;
	}

	


// 	bool cycle_detect_directed(int node, vector<int>&visited, int parent, vector<int>&stacks){
// 		visited[node] = true;
// 		stacks[node] = true;
// 		for(auto nbr : l[node]){
// 			if(!visited[nbr]){
// 				bool foundCycle = cycle_detect_directed(nbr, visited, node, stacks);
// 				if(foundCycle){
// 					return true;
// 				}
// 			}else if(stacks[nbr]){
// 				return true;
// 			}
// 		}
// 		stacks[node] = false;
// 		return false;
// 	}


// 	bool check_cycle_directed(int node){
        
// 		vector<int>visited(v, false);
// 		vector<int>stacks(v, false);
// 		int parent = -1;
// 		return cycle_detect_directed(node, visited, parent, stacks);
// 	}



	// khan algorithms
	void topological_sort(vector<int>&umap){
		vector<int> indegree(v, 0);
		for(int i=0; i<v; i++){
			for(auto nbr : l[i]){
				indegree[nbr]++;
			}
		}
		queue<int>q;
		for(int i=0; i<v; i++){
			if(indegree[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int f = q.front();
			q.pop();
			umap.push_back(f);

			for(auto nbr : l[f]){
				indegree[nbr]--;
				if(indegree[nbr] == 0){
					q.push(nbr);
				}
			}
		}
		return;
	}


};
    

    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        vector<int>umap;

        for(int i=0; i<prerequisites.size(); i++){
            g.addEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        
        
        g.topological_sort(umap);
        
        if(umap.size() == numCourses){
            return umap;
        }
        umap.clear();
        return umap;
    }
};






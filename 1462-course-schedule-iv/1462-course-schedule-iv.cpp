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



	void dfsHealper(int source, vector<bool>&visited){
		visited[source] = true;
		
		for(auto nbr : l[source]){
			if(!visited[nbr]){
				dfsHealper(nbr, visited);
			}
		}
		return;
	}

};

    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int len = prerequisites.size();
        vector<bool>ans;
        Graph g(numCourses);
        for(int i=0; i<len; i++){
            g.addEdge(prerequisites[i][0], prerequisites[i][1]);
        }
        for(int i=0; i<queries.size(); i++){
            vector<bool>visited(numCourses, false);
            g.dfsHealper(queries[i][0], visited);
            if(visited[queries[i][1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};


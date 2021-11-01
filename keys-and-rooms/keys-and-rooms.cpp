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

	void dfs(int source, vector<bool>&visited){
		
		dfsHealper(source, visited);
	}


};

    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<bool>visited(len, false);
        Graph g(len);
        for(int i=0; i<len; i++){
            for(int j=0; j<rooms[i].size(); j++){
                g.addEdge(i, rooms[i][j]);
            }
        }
        g.dfs(0, visited);
        for(int i=0; i<len; i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};
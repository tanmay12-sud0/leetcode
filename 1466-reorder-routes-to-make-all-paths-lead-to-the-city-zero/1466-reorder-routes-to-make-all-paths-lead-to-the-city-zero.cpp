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

	void addEdge(int x, int y, bool undir = true){
		l[x].push_back(y);
		if(undir){
			l[y].push_back(x);
		}
		return;
	}



	void dfsHealper(int source, vector<bool>&visited, set<pair<int, int>>&ss, int &cnt){
		visited[source] = true;
		
		for(auto nbr : l[source]){
			if(!visited[nbr]){
				dfsHealper(nbr, visited, ss, cnt);
                if(ss.count({source, nbr})){
                    cnt++;
                }
			}
		}
		return;
	}

};

    

    int minReorder(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        int cnt = 0;
        vector<bool>visited(n, false);
        set<pair<int, int>>ss;
        Graph g(n);
        for(int i=0; i<len; i++){
            g.addEdge(connections[i][0], connections[i][1]);
            ss.insert({connections[i][0], connections[i][1]});
        }
        
        g.dfsHealper(0, visited, ss, cnt);
        
        return cnt;
    }
};
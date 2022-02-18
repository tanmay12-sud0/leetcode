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

	void addEdge(int x, int y){
		l[x].push_back(y);
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
    
    
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int len = richer.size();
        int n = quiet.size();
        int cnt = 0;
        vector<int>hash;
        Graph g(n);
        for(int i=0; i<len; i++){
            g.addEdge(richer[i][1], richer[i][0]);
        }
        
        for(int i=0; i<n; i++){
            vector<bool>visited(n, false);
            g.dfsHealper(i, visited);
            int min_so_far = INT_MAX;
            int index = -1;
            for(int i=0; i<n; i++){
                if(visited[i]== true){
                    // cout << i << " ";
                    if(min_so_far > quiet[i]){
                        min_so_far = quiet[i];
                        index = i;
                    }
                }
            }
            hash.push_back(index);
        }
        
        return hash;
    }
};


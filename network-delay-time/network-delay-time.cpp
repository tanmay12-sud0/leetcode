class Solution {
public:
    
    
class Graph{
	list<pair<int, int>>*l;
	int v;

public:
	Graph(int n){
		v = n;
		l = new list<pair<int, int>>[v];
	}
	void addEdge(int x, int y, int w ,bool undir = false){
		l[x].push_back({y, w});
		if(undir){
			l[y].push_back({x, w});
		}
	}
	void djistra(int src, vector<int>&dist){
		
		set<pair<int, int>>s;
		dist[src] = 0;
		s.insert({0, src});

		while(!s.empty()){
			auto it = s.begin();
			int disTillNow = it->first;
			int node = it->second;
			s.erase(it);
			for(auto nbrPair : l[node]){
				int nbr = nbrPair.first;
				int currentEdge = nbrPair.second;
				if(currentEdge + disTillNow < dist[nbr]){
						// if present already then remove
					auto f = s.find({dist[nbr], nbr});
					if(f!=s.end()){
						s.erase(f);
					}

					dist[nbr] = currentEdge + disTillNow;
					s.insert({dist[nbr], nbr});
				}
			}
		}
		return;
	}
};
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         Graph g(n+1);
        vector<int>dist(n+1, INT_MAX);
        for(int i=0; i<times.size(); i++){
        	g.addEdge(times[i][0], times[i][1], times[i][2]);
        }
        g.djistra(k, dist);
        int max_sum = INT_MIN;
        for(int i=1; i<=n; i++){
        	max_sum = max(max_sum, dist[i]);
        }
        if(max_sum == INT_MAX){
        	return -1;
        }else{
        	return max_sum;
        }
    }
};
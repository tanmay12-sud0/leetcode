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

	int print(){
		for(int i=0; i<v; i++){
			// cout << i << ", ";
			int count =0;
			for(auto x : l[i]){
				// cout << x << "-->";
				count++;
			}
			if(count == v-2){
				return i;
			}
			// cout << endl;
		}
		return -1;
	}

};
    
    
    int findCenter(vector<vector<int>>& edges) {
        int len = edges.size();
        Graph g(len+2);
        for(int i=0; i<edges.size(); i++){
            g.addEdge(edges[i][0], edges[i][1]);
        }
        return g.print();
    }
};
    vector<int>inorder;

class Solution {
public:
    
    
class Graph{
public:
	int v;
	list<int>*l;
	Graph(int n){
		v = n;
		l = new list<int>[v];
		inorder.resize(n);
	}

	void addEdge(int x, int y, bool undir = true){
	l[x].push_back(y);
	inorder[x]++;
	inorder[y]++;
	if(undir){
		l[y].push_back(x);
	}
		return;
	}

	

	bool check(int a, int b){
		for(auto x : l[a]){
			if(x == b){
				return true;
			}
		}
		return false;
	}


};
    
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     
	Graph g(n);
	for(int i=0; i<roads.size(); i++){
		g.addEdge(roads[i][0], roads[i][1]);
	}
	int max_so = 0;
	for(int i=0; i<inorder.size(); i++){
		for(int j=i+1; j<inorder.size(); j++){
			int value=0;
			if(g.check(i, j)){
				value = inorder[i]+inorder[j]-1;
			}else{
				value = inorder[i]+inorder[j];
			}
            
			max_so = max(max_so, value);
		}
	}
    inorder.clear();
	return max_so;
    }
};
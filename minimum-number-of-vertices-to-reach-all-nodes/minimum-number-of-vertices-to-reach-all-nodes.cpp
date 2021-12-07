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

        void addEdge(int x, int y){
            l[x].push_back(y);
            return;
        }

        vector<int> topological_sort(){
            vector<int>inorder(v, 0);
            vector<int>umap;
            for(int i=0; i<v; i++){
                for(auto x : l[i]){
                    inorder[x]++;
                }
            }
            int count  = 0;
            for(int i=0; i<v; i++){
                
                if(inorder[i]==0){
                    umap.push_back(i);
                }
            }
            return umap;
        }

};
   
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        Graph g(n);
        for(int i=0; i<edges.size(); i++){
            g.addEdge(edges[i][0], edges[i][1]);
        }
        return g.topological_sort();
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //there should be atleast n-1 connctions to make the network connected
        if(connections.size()<n-1)
            return -1;
        
        //return  the number of computers that are not connected
        vector<int> parent(n,-1);
        
        int count=1;
        //union the connections
        for(int i=0;i<connections.size();i++)
        {
            uni(parent,connections[i][0],connections[i][1],count);
        }
        
        //the number of disconnected computers
        return n-count;
        
    }
    int findAbsParent(vector<int>& parent,int i)
    {
        while(parent[i]!=-1)
            i=parent[i];
        return i;
    }
    
    void uni(vector<int>& parent,int x,int y,int& count)
    {
        int parent1=findAbsParent(parent,x);
        int parent2=findAbsParent(parent,y);
        if(parent1!=parent2)
        {
            //if they both belong to different components
            //make them as single components
            parent[parent1]=parent2;
            count++;
        }
    }
};







// class Solution {
// public:
    
//     class Graph{
//         int v; 
//         list<pair<int, int>>l;
//         int count = 0;
//         public:
        
//             Graph(int n){
//                 v = n;
//             }
        
//             void addEdge(int U, int V){
//                 l.push_back(make_pair(U, V));
//                 return;
//             }
            
//             int Find_set(int i, vector<int>parent){
//                 if(parent[i] == -1){
//                     return i;
//                 }
//                 return parent[i] = Find_set(parent[i], parent);
//             }
        
//             void union_set(int v, int u, vector<int>&parent, vector<int>&rank){
//                 int s1 = Find_set(v, parent);
//                 int s2 = Find_set(u, parent);
//                 if(s1 != s2){
//                     if(rank[s1] < rank[s2]){
//                         parent[s1] = s2;
//                         rank[s2] += rank[s1];
//                     }else{
//                         parent[s2] = s1;
//                         rank[s1] += rank[s2];
//                     }
//                 }else{
//                     count++;
//                 }
//                 return;
//             }
            
//             int addKro(){
//                 vector<int>parent(v, -1);
//                 vector<int>rank(v, 1);
//                 for(auto x : l){
//                     int a = x.first;
//                     int b = x.second;
//                     union_set(a,b, parent, rank);
//                 }
//                 int min = 0;
//                 for(auto x : parent){
//                     cout << x << ", ";
//                     if(x == -1){
//                         min++;
//                     }
//                 }
//                 if(count < min-1){
//                     return -1;
//                 }
//                 return min-1;
//             }
//     };
    

//     int makeConnected(int n, vector<vector<int>>& connections) {
//         Graph g(n);
//         for(int i=0; i<connections.size(); i++){
//             g.addEdge(connections[i][0], connections[i][1]);
//         }
//         return g.addKro();
//         // return 0;
//     }
// };
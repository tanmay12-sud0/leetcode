bool comp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return a.first<b.first;
}
class Solution {
public:
   long long int par[1005];
   long long  int findpar(int x){
        if(par[x]==-1)
            return x;
        return par[x]=findpar(par[x]);
    }
    void merge(int x,int y){
        par[y]=x;

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int> > > edges;
        memset(par,-1,sizeof(par));
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                if(i==j)
                    continue;
                int sum=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({sum,{i,j}});
            }
        }
        sort(edges.begin(),edges.end(),comp);
        int ans=0,count=0;
        for(int i=0;i<edges.size()&&count<points.size()-1;i++){
            int dist=edges[i].first;
            int x=edges[i].second.first;
            int y=edges[i].second.second;
           long long int parx=findpar(x);
           long long int pary=findpar(y);
            if(parx!=pary){
                ans+=dist;
                merge(parx,pary);
                count++;
            }
        }
        return ans;
    }
};




// class Solution {
// public:
    
//     class Graph{
// public:
//   int v;
//   vector<pair<int, int>>*l;

//   Graph(int n){
//     v = n;
//     l = new vector<pair<int, int>>[n];
//   }

//   void addEdge(int x, int y, int w){
//     l[x].push_back({y,w});
//     l[y].push_back({x,w});
//   }

//   int prim_mst(){
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
//     vector<bool>visited(v, 0);
//     int ans = 0;
//     pq.push(make_pair(0,0));

//     while(!pq.empty()){
//       auto best = pq.top();
//       pq.pop();
//       int to = best.second;
//       int weight = best.first;

//       if(visited[to]){
//         continue;
//       }
      
//       ans += weight;
//       visited[to] = true;

//       for(auto x : l[to]){
//         if(!visited[x.first]){
//           pq.push(make_pair(x.second, x.first));
//         }
//       }
//     } 
//     return ans;
//   }

// };

//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         Graph g(n);
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1;j<n; j++){
//             int w = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
//             cout << w << endl;
//             g.addEdge(i,j,w);
//         }
        
//     }
//     return g.prim_mst();
//     }
// };
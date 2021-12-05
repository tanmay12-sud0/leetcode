class Solution {
public:
    
    void NumberOfCities(int n, int i, vector<pair<int, int>> graph[n], int distanceThreshold, vector<int> &citiesCount){
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> distance(n, INT_MAX);
        
        distance[i] = 0;
        pq.push({0, i});
        
        while(!pq.empty()){
            int current = pq.top().second;
            int previousDistance = pq.top().first;
            pq.pop();
            
            for(auto it : graph[current]){
                if(previousDistance + it.second < distance[it.first]){
                    distance[it.first] = previousDistance + it.second;
                    pq.push({distance[it.first], it.first});
                }
            }
        }
        
        // keep count of no. of cities that can be visited(<= distanceThreshold) by city i in citiesCount vector
        int count = 0;
        for(int j = 0; j < n; j++){
            if(i != j && distance[j] <= distanceThreshold)  count++;
        }
        
        citiesCount.push_back(count);
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int, int>> graph[n];
        vector<int> citiesCount;
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        // get distance of city i from every other cities
        for(int i = 0; i < n; i++){
            NumberOfCities(n, i, graph, distanceThreshold, citiesCount);
        }
        
        // find the city which can reach least number of cities
        int minCities = INT_MAX;
        int output = 0;
        int i;
        for(i = 0; i < citiesCount.size(); i++){
            if(citiesCount[i] <= minCities){
                minCities = citiesCount[i];
                output = i;
            }
        }
        
         return output;
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
//     l[x].push_back({w,y});
//     l[y].push_back({w,x});
//   }


//   bool dijkshtra(int source, int threeShold){
//       vector<int>dist(v, INT_MAX);
//       set<pair<int, int>>s;
//       dist[source] = 0.00;
//       s.insert({0,source});

//       while(!s.empty()){
//         auto it = s.begin();
//         int distTillNow = it->first;
//         int node = it->second;
//         s.erase(it);

//         for(auto nbrPair : l[node]){
//             int edgeValue = nbrPair.first;
//             int nbr = nbrPair.second;


//             if(edgeValue + distTillNow < dist[nbr]){

//                 auto it = s.find({dist[nbr], nbr});
//                 if(it != s.end()){
//                   s.erase(it);
//                 }
//                 dist[nbr] = edgeValue + distTillNow;
//                 s.insert({dist[nbr], nbr});
//             }
//         }
//       }
//         int counts = 0;
//       for(int i=0; i<v; i++){
//        if(dist[i] <= threeShold){
//            counts++;
//        }
//       }
      

//       return false;
//   }

  
// };
    
    
    
    
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//     Graph g(n);
//     for(int i=0; i<edges.size(); i++){
//       g.addEdge(edges[i][0], edges[i][1] , edges[i][2]);
//     }
//     int threeShold = 4;
//      for(int i = n-1; i>=0; i--){
//          if(g.dijkshtra(i, threeShold)){
//              return i;
//          }
//      }
//          for(i = 0; i < citiesCount.size(); i++){
//             if(citiesCount[i] <= minCities){
//                 minCities = citiesCount[i];
//                 output = i;
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    void fun(vector<int>&color_list, vector<vector<int>>&list,int N)
    {
        for(int i = 1;i<=N;i++)
        {
                /*For each  node check which colors are used by neighbours*/
                vector<bool>neighbour_color(5, false);
                /*Loop on all neighbours*/
                for(auto j : list[i])
                {
                    if(color_list[j] != -1)
                    neighbour_color[color_list[j]] = true;
                }
                /*Choose available color*/
                for(int k = 1;k<=4;k++)
                {
                    if(!neighbour_color[k]){
                    color_list[i] = k;break;}
                }
        }
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>>list(N+1);
        /*You created your adjacency list*/
        for(auto node : paths)
        {
            list[node[0]].push_back(node[1]);
            list[node[1]].push_back(node[0]);
        }
        /*Initially no color is used.*/
        vector<int>color_list(N+1,-1);
        /*Question is same as k-coloring prob.*/
        fun(color_list, list, N);
        /*Erase First Index as we have stored color[i] for ith garden */
        vector<int>::iterator it;
        it = color_list.begin(); 
        color_list.erase(it); 
        return color_list;
    }
};
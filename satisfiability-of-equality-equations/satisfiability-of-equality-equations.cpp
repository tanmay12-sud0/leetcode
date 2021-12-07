bool compare(const string &a, const string &b){
    return a[1]>b[1];
}


class Solution {
public:
    
    class Graph{
    int V;
    list<pair<int, int>>l;

public:
    Graph(int v){
        V = v;
        // l = new list<int>[v];
    }

    void addEdge(int a, int b){
        l.push_back(make_pair(a, b));
        return;
    }

    int findset(int i, vector<int>&parent){
        if(parent[i] == -1){
            return i;
        }
        return findset(parent[i], parent);
    }

    void union_set(int x, int y, vector<int>&parent){
        int s1 = findset(x, parent);
        int s2 = findset(y, parent);
        if(s1 != s2){
            parent[s2] = s1;
        }
        return;
    }

    bool check_equality(vector<string>& equ){
        int len = equ.size();
        vector<int>parent(40, -1);
        for(auto x : equ){
            char first = x[0];
            char second = x[1];
            char third = x[2];
            char fourth = x[3];
            if(second == '=' and third == '='){
                int s1 = findset(int(first-'a'), parent);
                int s2 = findset(int(fourth-'a'), parent);
                if(s1 != s2){
                    union_set(s1, s2, parent);
                }
            }
            if(second == '!' and third == '='){
                int s1 = findset(int(first-'a'), parent);
                int s2 = findset(int(fourth-'a'), parent);
                if(s1 == s2){
                    return false;
                }
            }
        }
        return true;
    }
    

};

    bool equationsPossible(vector<string>& equations) {
        Graph g(10);
        sort(equations.begin(), equations.end(), compare);
        return g.check_equality(equations);
    }
};
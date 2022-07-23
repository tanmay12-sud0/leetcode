class Solution {
public:
    
    vector<int>left;
    stack<int>leftS;
    vector<int>right;
    stack<int>rightS;
    void checkLeft(vector<int> heights){
        int n = heights.size();
        for(int i=0; i<n; i++){
            if(leftS.empty()){
                left.push_back(-1);
            }else{
                while(!leftS.empty() and heights[leftS.top()] >= heights[i]){
                    leftS.pop();
                }
                if(leftS.empty()){
                    left.push_back(-1);
                }else{
                    left.push_back(leftS.top());
                }
            }
            leftS.push(i);
        }
        return;
    }
    
    void checkRight(vector<int> heights){
        int n = heights.size();
        for(int i=n-1; i>=0; i--){
            if(rightS.empty()){
                right.push_back(n);
            }else{
                while(!rightS.empty() and heights[rightS.top()] >= heights[i]){
                    rightS.pop();
                }
                if(rightS.empty()){
                    right.push_back(n);
                }else{
                    right.push_back(rightS.top());
                }
            }
            rightS.push(i);
        }
        reverse(right.begin(), right.end());
        return;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        checkLeft(heights);
        checkRight(heights);
        // for(auto x : left){
        //     cout << x << ", ";
        // }
        // cout << endl;
        // for(auto x : right){
        //     cout << x << ", ";
        // }
        // cout << endl;
        int max_so_far = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            max_so_far = max(max_so_far, (right[i]-(left[i])-1)*heights[i]);
        }
        return max_so_far;
    }
};
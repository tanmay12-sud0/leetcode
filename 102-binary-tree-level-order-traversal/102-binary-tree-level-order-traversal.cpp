
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root == NULL){
            return v;
        }
        queue<TreeNode* > q;
        vector<int>hash;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                v.push_back(hash);
                hash.clear();
                if(q.size() != 0){
                    q.push(NULL);    
                }
            }else{
                hash.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return v;
    }
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>hash;
        vector<int>umap;
        int count = 0;
        if(root==NULL){
            return hash;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        hash.push_back({root->val});
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(q.size()){
                    if(count%2!=0){
                        hash.push_back(umap);
                        umap.clear();
                    }else{
                        reverse(umap.begin(), umap.end());
                        hash.push_back(umap);
                        umap.clear();
                    }
                }else{
                    break;
                }
                q.push(NULL);
                count++;
                continue;
            }
            if(temp->left){
                q.push(temp->left);
                umap.push_back(temp->left->val);
            }
            if(temp->right){
                q.push(temp->right);
                umap.push_back(temp->right->val);
            }
        }
        return hash;
    }
};




// o(n*n) approch

// class Solution {
// public:
    
//     int depth(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         int h1 = depth(root->left);
//         int h2 = depth(root->right);
//         return max(h1, h2) + 1;
//     }
    
//     void printAtDistanceKA(TreeNode* root, int k, vector<int>&hash){
//         if(root == NULL){
//             return;
//         }
//         if(k==1){
//             hash.push_back(root->val);
            
//         }
//         printAtDistanceKA(root->left, k-1, hash);
//         printAtDistanceKA(root->right, k-1, hash);
//         return;
        
//     }
    
//     void printAtDistanceKB(TreeNode* root, int k, vector<int>&hash){
//         if(root == NULL){
//             return;
//         }
//         if(k==1){
//             hash.push_back(root->val);
            
//         }
//         printAtDistanceKB(root->right, k-1, hash);
//         printAtDistanceKB(root->left, k-1, hash);
//         return;
        
//     }
    
//     vector<vector<int>> printAllLevel(TreeNode* root){
//         vector<vector<int>>hash_new;
//         vector<int>hash;
//         int len = depth(root);
//         for(int i=1; i<=len; i++){
//            if(i%2==0){
//                 printAtDistanceKB(root, i, hash);
//             hash_new.push_back(hash);
//             hash.clear();
//            }else{
//                 printAtDistanceKA(root, i, hash);
//             hash_new.push_back(hash);
//             hash.clear();
//            }
//         }
//         return hash_new;
//     }
    
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//          return printAllLevel(root);
//     }
// };

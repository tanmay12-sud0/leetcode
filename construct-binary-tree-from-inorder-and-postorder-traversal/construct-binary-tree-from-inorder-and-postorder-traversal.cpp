class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	  //assign rootIndex to last index of postorder because postorder follows: L R Root
       int rootIndex = postorder.size()-1;
	   
        return helper(postorder, rootIndex, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode*  helper(vector<int>& postorder, int& rootIndex, vector<int>& inorder, int start, int end) {
		// if rootIndex can't be less than 0 and start can't be greater than end in that case return Null pointer.
        if(rootIndex < 0 || start > end) return nullptr;
        
		// calculate the distance between first inorder element and last element (i.e, the root is present). 
        int pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, postorder[rootIndex]));
		
        TreeNode* root = new TreeNode(postorder[rootIndex]);
		rootIndex--;          //decrement the root Index.
        root -> right = helper(postorder, rootIndex, inorder, pos + 1, end);   //right node
        root -> left = helper(postorder, rootIndex, inorder, start, pos - 1);   //left node
        return root;  
    }
};
















// class Solution {
// public:
//     int i = 0;
//     TreeNode* buildTrees(vector<int>& preorder, vector<int>& inorder,int s, int e){
//         if(s>e or (preorder.size()-1-i) < 0){
//             return NULL;
//         }
//         TreeNode* root = new TreeNode(preorder[preorder.size()-1-i]);
//         int index=-1;
//         for(int j=s; j<=e; j++){
//             if(preorder[i] == inorder[j]){
//                 index = j;
//                 break;
//             }
//         }
        
//         i++;
//             root->right = buildTrees(preorder, inorder, index+1, e);

//             root->left = buildTrees(preorder, inorder, s,  index-1);

//         return root;
//     }
    
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
//         int e = preorder.size()-1;
//         return buildTrees(preorder, inorder, 0, e);
//     }
// };




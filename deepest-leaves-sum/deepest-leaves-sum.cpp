
class Solution {
public:
    int deepest = 0, sum = 0;
int deepestLeavesSum(TreeNode* root, int depth = 0) {
	if(!root) return 0;  // current node is NULL - just return.
	if(!root -> left && !root -> right) // if current is a leaf node
		if(depth == deepest) sum += root -> val;  // if depth is exactly equal to deepest, add to sum
		else if(depth > deepest) sum = root -> val, deepest = depth; // found a more deeper leaf node, reset sum and update deepest
	deepestLeavesSum(root -> left, depth + 1);   // recurse for the left, 
	deepestLeavesSum(root -> right, depth + 1);  // and the right node of the current node
	return sum; // finally return the sum accumulated till now which will be sum of value of deepest leaves
}

    
};









// int sum = 0;
    
//     void sumD(TreeNode* root, int level, int &maxLevel){
//         if(root==NULL){
//             return;
//         }
//         if(maxLevel == level){
//             sum += root->val;
//         }else if(level>maxLevel){
//             sum = root->val;
//             maxLevel = level;
//         }
//         sumD(root->left, level+1, maxLevel);
//         sumD(root->right, level+1, maxLevel);
//         return; 
//     }

    
//     int deepestLeavesSum(TreeNode* root) {
//         int maxLevel = -1;
//         sumD(root, 0, maxLevel);
//         return sum;
//     }
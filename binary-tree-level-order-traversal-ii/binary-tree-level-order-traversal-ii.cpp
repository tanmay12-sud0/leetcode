
class Solution {
public:
    vector<vector<int>>hash;
    vector<int>hash1;
int height(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1, h2) + 1;
}

void printKLevel(TreeNode* root, int k){
	if(root == NULL){
		return;
	}
	if(k == 1){
		hash1.push_back(root->val);
	}
	printKLevel(root->left, k-1);
	printKLevel(root->right, k-1);
	return;
}

void printAllLevel(TreeNode* root){
	if(root == NULL){
		return;
	}
	int h1 = height(root);
	for(int i=h1; i>0; i--){
		printKLevel(root, i);
		hash.push_back(hash1);
        hash1.clear();
	}
	return;
}
        

    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        printAllLevel(root);
        return hash;
    }
};





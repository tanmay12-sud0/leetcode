class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};









// class Codec {
// public:
    
//     int i = 0;
//     TreeNode* buildTrees(vector<int>& preorder, vector<int>& inorder,int s, int e){
//          // cout << preorder <<", " <<  inorder<< ", " << s << ", " <<  e << endl;
//         if(s > e){
//             return NULL;
//         }
//         TreeNode* root = new TreeNode(preorder[i]);
//         int index;
//         for(int j=s; j<=e; j++){
//             if(preorder[i] == inorder[j]){
//                 index = j;
//                 break;
//             }
//         }
//         i++;
        
//         root->left = buildTrees(preorder, inorder, s,  index-1);
//         root->right = buildTrees(preorder, inorder, index+1, e);
//         return root;
//     }
    
    
    
//     void inorder(TreeNode* root, string &s){
//         if(root==NULL){
//             return;
//         }
//         inorder(root->left, s);
//         s += to_string(root->val);
//         s += ",";
//         inorder(root->right, s);
//         return;
//     }
    
//     void preorder(TreeNode* root, string &s){
//         if(root==NULL){
//             return;
//         }
        
//         s += to_string(root->val);
//         s += ",";
//         preorder(root->left, s);
//         preorder(root->right, s);
//         return;
//     }
    

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string inorders;
//         string preorders;
//         inorder(root, inorders);
//         preorder(root, preorders);
//         return inorders+preorders;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         int n = data.length();
//         string in = data.substr(0, n/2);
//         string pre = data.substr(n/2);
//         vector<int>preorder;
//         vector<int>inorder;
//         cout << in << ", " << pre << "hello" << endl;
//         string f="";
//         for(int i=0; i<in.length(); i++){
//             if(in[i] == ','){
//                 inorder.push_back(stoi(f));
//                 f = "";
//             }else{
//                 f += in[i];    
//             }
//         }
//         f = "";
//         for(int i=0; i<pre.length(); i++){
//             if(pre[i] == ','){
//                 preorder.push_back(stoi(f));
//                 f = "";
//             }else{
//                 f += pre[i];    
//             }
//         }
//         for(int i=0; i<preorder.size(); i++){
//             cout << preorder[i] << ", ";
//         }
//         cout << endl;
//         for(int i=0; i<inorder.size(); i++){
//             cout << inorder[i] << ", ";
//         }
//         return buildTrees(preorder, inorder, 0, preorder.size()-1);
//     }
// };


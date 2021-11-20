class Codec {
public:   
    string serialize(TreeNode* root) {
       string res ;
       solveS(root,res); 
        return res;
    }
    
    void solveS(TreeNode* root,string &res){
        if(!root)return ; 
        
        res+= to_string(root->val)+",";
        
        solveS(root->left,res) ;
        solveS(root->right,res) ;
        
    }
    
    void spaceIt(string &x){
        for(int i=0;i<x.length();i++){
            if(x[i]==',')x[i]=' ' ;
        }
    }
        
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {      
        if(data.empty())return NULL ;
        spaceIt(data); 
        string temp ;
        stringstream ss ;
        ss<<data ;
        
        TreeNode* root= NULL ;
        while(ss>>temp){
            int toInt = stoi(temp);
            insert(toInt,root) ;
        }
        
        return root ;
    }
    void insert(int x,TreeNode* &root){
        TreeNode* curr = root ;
        TreeNode* prev = NULL ;
        
        if(!root){
            root = new TreeNode((x) ) ;
            return  ;
        }
    
        while(curr){
            prev=curr ;
            if(curr->val>x ){
                curr=curr->left ;
            }else{
                curr=curr->right ;
            }
        }
        if(prev->val > x){
            prev->left = new TreeNode(x) ;
        }else{
            prev->right = new TreeNode(x);
        }
    }
};
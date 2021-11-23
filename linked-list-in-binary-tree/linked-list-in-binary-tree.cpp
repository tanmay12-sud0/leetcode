class Solution {
public:
    bool findKro(ListNode* head, TreeNode* root){
        if(!head)
            return true;
        if(root==NULL){
            return false;
        }
        
        if(root->val != head->val){
           return false;
        }
        
        bool leftans = findKro(head->next, root->left);
        bool rightans = findKro(head->next, root->right);
       
        if(leftans){
            return leftans;
        }
        return rightans;
    }
    
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(findKro(head, root))
            return true;
        if(!head) return true;
        if(!root) return false;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
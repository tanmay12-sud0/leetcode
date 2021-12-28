class Solution {
public:

    TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return new TreeNode(head->val);
    
    ListNode* fast = head;
    ListNode *slow = head;
    ListNode* prev=head;
    
    while(fast!= NULL && fast->next!= NULL){
        fast=fast->next->next;
        prev =slow;
        slow = slow->next;
    }
    
    prev->next = NULL;
    
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    
    return root;
   }     

};
// class Solution {
// public:
    
//     vector<ListNode*> midPoint(ListNode* head){
// 	    if(head == NULL or head->next == NULL){
// 		    return {NULL, NULL};
// 	    }
//         ListNode* prev = NULL;
// 	    ListNode* slow = head;
// 	    ListNode* fast = head->next;

// 	    while(fast!= NULL and fast->next!= NULL){
// 		    fast = fast->next->next;
//             prev = slow;
// 		    slow = slow->next;
// 	    }
// 	    return {prev, slow};
//     }
    
    
//     TreeNode* buildArrray(ListNode* head){
//         if(head == NULL){
//             return NULL;
//         }
//         vector<ListNode*>tanmy = midPoint(head);
//         ListNode* prev = tanmy[0];
//         ListNode* mid = tanmy[1];
//         ListNode* temp = NULL;
//         cout << prev->val << ", " << mid->val << endl;
//         if(mid->next){
//             temp = mid->next;
//         }
//         if(prev and prev->next){
//             prev->next = NULL;
//         }
        
//         TreeNode* root = new TreeNode(mid->val);
//         root->left = buildArrray(head);
//         root->right = buildArrray(temp);
//         return root;
//     }
    
    
//     TreeNode* sortedListToBST(ListNode* head) {
//         return buildArrray(head);
//     }
// };


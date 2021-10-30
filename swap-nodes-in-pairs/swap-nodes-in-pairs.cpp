
class Solution {
public:
    
    void swap(ListNode* node){
        if(node == NULL or node->next == NULL){
            return;
        }
        ListNode* first = node->next;
        ListNode* second = NULL;
        if(first){
            second = first->next;
        }
        if(second){
            ListNode* secondText = second->next;
            node->next = second;
            second->next = first;
            first->next = secondText;
            swap(first);
        }
        
    }
    
    
    
    ListNode* swapPairs(ListNode* head) {
       
        if(head == NULL ){
            return NULL;
        }
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        swap(dummy);
        return dummy->next;
    }
};
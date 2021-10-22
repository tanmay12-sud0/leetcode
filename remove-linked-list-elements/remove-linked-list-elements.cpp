
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
        while( head!= NULL and head->val == val){
            head = head->next;
        }
        if(!head){
            return NULL;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            if(temp->val != val){
                prev = temp;
                temp = temp->next;
            }else{
                prev->next = temp->next;
                temp = prev->next;
            }
        }
        return head;
    }
};

class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(length(head) == 0 or k==0 or head==NULL){
            return head;
        }
        int pos = length(head) - k%length(head);
        ListNode* p = head;
        
        while(pos>1){
            pos--;
            p = p->next;
        }
        
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        
        ListNode* q = p->next;
        p->next = NULL;
        return q;
    }
};
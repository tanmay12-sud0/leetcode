
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        while(q != NULL){
            if(p->val == q->val){
                p->next = q->next;
                q = p->next;
            }else{
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};
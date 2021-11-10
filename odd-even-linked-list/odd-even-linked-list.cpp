
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        
        ListNode* p=head, *temp1 = head;
        ListNode* q=head->next, *temp2 = head->next;
        while(q and q->next){
            p->next = p->next->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = temp2;
        return temp1;
   
    }
};
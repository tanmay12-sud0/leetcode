
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return NULL;
        }
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* temp = head;
        ListNode* p = dummy1;
        ListNode* q = dummy2;
        while(temp!=NULL){
            if(temp->val < x){
                p->next = temp;
                p = p->next;
            }else{
                q->next = temp;
                q = q->next;
            }
            temp = temp->next;
        }
        q->next = NULL;
        p->next = dummy2->next;
        return dummy1->next;
    }
};
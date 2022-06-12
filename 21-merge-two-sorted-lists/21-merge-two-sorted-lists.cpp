
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p != NULL and q != NULL){
            if(p->val <= q->val){
                temp->next = p;
                temp = temp->next;
                p = p->next;
            }else{
                temp->next = q;
                temp = temp->next;
                q = q->next;
            }
            
        }
        if(p){
            temp->next = p;
        }
        if(q){
            temp->next = q;
        }
        return dummy->next;
    }
};
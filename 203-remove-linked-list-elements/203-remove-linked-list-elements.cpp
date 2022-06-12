
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL and head->val == val){
            head = head->next;
        }
        ListNode* q = head;
        ListNode* p;
        while(q != NULL){
            if(q->val == val){
                p->next = q->next;
                q = p->next;
            }else{
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
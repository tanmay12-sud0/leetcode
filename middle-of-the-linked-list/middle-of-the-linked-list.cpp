class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*p = head;
        ListNode*q = head;
        if(p->next == 0){
            return p;
        }
        while(q->next!=NULL){
            p = p->next;
            q = q->next;
            q = q->next!=NULL ? q->next : q;
        }
        return p;
    }
};
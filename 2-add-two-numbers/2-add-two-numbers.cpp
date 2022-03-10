class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        int carry =0;
        ListNode* p = l1;
        ListNode*q = l2;
        ListNode* curr = dummy;
        while(p!=NULL or q!= NULL){
            int a = p?p->val:0;
            int b = q?q->val:0;
            int sum = a+b+carry;
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            curr = curr->next;
            if(p){p = p->next;}
           if(q){ q = q->next;}
        }
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
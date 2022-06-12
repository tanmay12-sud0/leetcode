class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;
        while(p != NULL or q != NULL){
            int a = p?p->val:0;
            int b = q?q->val:0;
            int value = a + b + carry;
            temp->next = new ListNode(value%10);
            temp = temp->next;
            carry = value/10;
            if(p){p = p->next;}
           if(q){ q = q->next;}
        }
        while(carry>0){
            temp->next = new ListNode(carry%10);
            carry /= 10;
        }
        return dummy->next;
    }
};
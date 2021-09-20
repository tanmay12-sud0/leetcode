/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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


// ListNode* dummy = new ListNode(0);
//         ListNode *p = l1, *q = l2, *curr = dummy;
//         int carry =0;
//         while(p != NULL || q != NULL){
//             int x = p!=NULL?p->val:0;
//             int y = q!=NULL?q->val:0;
//             int sum = x+y+carry;
//             curr->next = new ListNode(sum%10);
//             curr = curr->next;
//             carry = sum/10;
//             if(p != NULL)p = p->next;
//             if(q != NULL)q = q->next;
//             // q = q->next;
            
//         }
//         if(carry >0){
//             curr->next = new ListNode(carry);
//         }
//         return dummy->next;
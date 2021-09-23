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
    ListNode* mergeTwoLists(ListNode* l1 , ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
         ListNode* c; 
        if(a == nullptr){
            return b;
        }
        if(b == nullptr){
            return a;
        }
        if(a->val <= b->val){
            c= a;
            c->next = mergeTwoLists(a->next, b);
        }else{
            c = b;
            c->next = mergeTwoLists(a, b->next);
        }
        return c;
       
    }
};
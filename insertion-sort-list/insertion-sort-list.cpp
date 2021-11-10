
class Solution {
public:
    
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == NULL){
            return b;
        }
        if(b == NULL){
            return a;
        }
        ListNode* c;
        if(a->val < b->val){
            c = a;
            c->next = merge(a->next, b);
        }else{
            c = b;
            c->next = merge(a, b->next);
        }
        return c;
    }
    
    
    ListNode* midPoint(ListNode* head){
        if(head==NULL or head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* mid = midPoint(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;
        
        a = insertionSortList(a);
        b = insertionSortList(b);
        
        ListNode* c = merge(a, b);
        return c;
    }
};


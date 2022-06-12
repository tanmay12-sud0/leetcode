class Solution {
public:
    ListNode* middleNode(ListNode* head){
        if(head==NULL or head->next == NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* last = head;
        while(fast != NULL and fast->next != NULL){
            last = last->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        return last;
    }
};
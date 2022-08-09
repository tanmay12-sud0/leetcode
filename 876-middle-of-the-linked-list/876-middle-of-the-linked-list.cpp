class Solution {
public:
    ListNode* middleNode(ListNode* head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
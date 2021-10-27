
class Solution {
public:
    
    int length(ListNode* head){
        int count = 0;
        while(head!= NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    
    
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        ListNode* fast = head;
        ListNode* slow = head;
        if(head==NULL and head->next==NULL){
            return head;
        }
        int count =0;
        while(count != len-k){
            count++;
            fast = fast->next;
        }
        count = 1;
        while(count != k){
            count++;
            slow = slow->next;
        }

        swap(slow->val, fast->val);
        return head;
    }
};
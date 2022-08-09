class Solution {
public:
    int len(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(n==1){
            ListNode* temp = head;
            while(temp->next!=NULL){
                slow = temp;
                temp = temp->next;
            }
            if(len(head) == 1){
                head = NULL;
                return head;
            }else{
                slow->next = NULL;
            }
           
            return head;
        }
        int cnt = 1;
        while(cnt < n){
            cnt++;
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next){
            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }
        return head;
    }
};
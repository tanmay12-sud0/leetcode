
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head->next==NULL){
            return NULL;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(count%2!=0 or count%2==0){
            int n = count/2;
            ListNode* temp = head;
            int count = 0;
            while(count < n-1){
                temp = temp->next;
                count++;
            }
            ListNode* temp1 = temp->next;
            temp->next = temp1->next;
        }
        return head;
    }
};
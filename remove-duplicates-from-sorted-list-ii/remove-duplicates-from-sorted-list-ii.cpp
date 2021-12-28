class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* p = head;
        ListNode* q = head->next;
        int value = -110;
        while(p!=NULL){
            if(q==NULL and p->val != value){
                temp->next = p;
                temp = p;
                temp->next == NULL;
                p = p->next;
            }
            else if(q==NULL and p->val == value){
                break;
            }
            else if(p->val == q->val or p->val == value){
                value = p->val;
                p = p->next;
                q = q->next;
            }
            else if(p->val != q->val and p->val != value){
                temp->next = p;
                temp = p;
                
                p = p->next;
                q = q->next;
                temp->next = NULL;
            }
        }
        return dummy->next;
    }
};


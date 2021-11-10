class Solution {
public:
    
    void reverse(ListNode* &head){
	    ListNode* c = head;
	    ListNode* p = NULL;
	    ListNode* n;

	    while(c!=NULL){
		    n = c->next;
		    c->next = p;
		    p = c;
		    c = n;
	    }
	    head = p;
	    return;
}

ListNode* midPoint(ListNode* head){
	if(head == NULL or head->next == NULL){
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;

	while(fast!= NULL and fast->next!= NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
    
    
void palindrome(ListNode* &head){
	if(head == NULL or head->next == NULL){
		return;
	}
	ListNode* mid = midPoint(head);
	ListNode* temp = mid->next;
	mid->next = NULL;
	reverse(temp);
	mid->next = temp;
	return;
}

    
    
    void reorderList(ListNode* head) {
        ListNode *curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        if(count==1 || count==2){
            return;
        }
        palindrome(head);
        ListNode* mid = midPoint(head);
        ListNode* p = head;
        ListNode* q = mid->next;
        ListNode* s  = p->next;
        ListNode* a = mid->next->next;
        while(a!=NULL){
            //s = p->next;
            p->next = q;
            q->next=s;
            p=s;
            s=s->next;
                q=a;
            a=a->next;
           
        }
        p->next = q;
            q->next=s;
        if(count%2!=0){
            mid->next=NULL;
        }else{
            mid->next->next=NULL;
        }
        
        
        return;
    }
};

class Solution {
public:
    
    void insertAtHead(ListNode* &head, int d){
	if(head == NULL){
		head = new ListNode(d);
		return;
	}

	ListNode* temp = new ListNode(d);
	temp->next = head;
	head = temp;
	return;
}
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != NULL){
            s1.push(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            s2.push(temp2->val);
            temp2 = temp2->next;
        }
        
        int carry = 0;
        ListNode * dummy = NULL;
        
        while(!s1.empty() or !s2.empty()){
            int x = s1.empty() ? 0 : s1.top();
            int y = s2.empty() ? 0 : s2.top();
            int sum = x+y+carry;
            insertAtHead(dummy ,sum%10);
            carry = sum/10;
            if(!s1.empty()){
                s1.pop();
            }
            if(!s2.empty()){
                s2.pop();
            }
        }
        while(carry > 0){
            insertAtHead(dummy ,carry%10);
            carry = carry/10;
        }
        return dummy;
    }
};
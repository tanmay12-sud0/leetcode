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

 
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL){
		return true;
	}
	ListNode* mid = midPoint(head);
	ListNode* temp = mid->next;
	mid->next = NULL;
	reverse(temp);
	mid->next = temp;
	
	ListNode* first = head;
	ListNode* second = mid->next;

	while(second!=NULL){
		
		if(first->val != second->val){
			return false;
		}
		first = first->next;
		second = second->next;
	}
	return true;
    }
};
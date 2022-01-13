
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        int max_so_far = 0;
        temp = head;
        while(temp!=NULL){
            max_so_far = max(max_so_far, temp->val + st.top());
            st.pop();
            temp = temp->next;
        }
        return max_so_far;
    }
};
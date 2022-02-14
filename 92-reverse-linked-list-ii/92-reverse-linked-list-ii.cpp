
class Solution {
public:
   
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL ){
            return NULL;
        }
        int count = 0;
        stack<int>st;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            if(count >= left and count <= right){
                st.push(temp->val);
            }
            temp = temp->next;
        }
        cout << st.size() << endl;
        temp = head;
        count = 0;
        while(temp != NULL){
            count++;
            if(count >= left and count <= right){
                temp->val = st.top();
                st.pop();
            }
            temp = temp->next;
        }
        return head;
    }
};
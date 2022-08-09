class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL){
            return false;
        }
        unordered_map<ListNode*, int>hash;
        ListNode* temp = head;
        while(temp != NULL){
            if(hash.count(temp)){
                return true;
            }
            hash[temp]++;
            temp = temp->next;
        }
        return false;
    }
};

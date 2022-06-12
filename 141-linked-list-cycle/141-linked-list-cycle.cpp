
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int>hash;
        ListNode* p = head;
        while(p != NULL){
            if(hash.count(p)){
                return true;
            }
            hash[p]++;
            p = p->next;
        }
        return false;
    }
};

class Solution {
public:
        vector<int>hash;
    int i =0;
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp!=NULL){
            hash.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int len = hash.size();
        int x = rand()%len;
        return hash[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
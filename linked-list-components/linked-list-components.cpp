
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int>hash;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            if(hash.count(temp->val) ){
                count++;
                while(temp->next!=NULL and hash.count(temp->next->val)){
                    temp = temp->next;
                }
            }
            temp = temp->next;
        }
        return count;
    }
};
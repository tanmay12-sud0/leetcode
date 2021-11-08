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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>hash;
        if(head==NULL or head->next==NULL or head->next->next==NULL){
            hash.push_back(-1);
             hash.push_back(-1);
            return hash;
        }
        ListNode * first = head;
        ListNode * second = head->next;
        ListNode* third = head->next->next;
        int count = 2;
        while(third!=NULL){
            if(second->val < first->val and second->val < third->val){
                hash.push_back(count);
            }else if(second->val > first->val and second->val > third->val){
                hash.push_back(count);
            }
            first = first->next;
            second = second->next;
            third = third->next;
            count++;
        }
        if(hash.size() == 0){
             hash.push_back(-1);
             hash.push_back(-1);
             return hash;
        }else if(hash.size() == 1){
            hash.clear();
             hash.push_back(-1);
             hash.push_back(-1);
            return hash;
        }else{
            int maxDis = abs(hash[0] - hash[hash.size()-1]);
            int minDis = INT_MAX;
            for(int i=1; i<hash.size(); i++){
                if(abs(hash[i-1]-hash[i]) < minDis){
                    minDis = abs(hash[i-1]-hash[i]);
                }
            }
            hash.clear();
            hash.push_back(minDis);
            hash.push_back(maxDis);
            return hash;
        }
         
        return hash;
        
    }
};
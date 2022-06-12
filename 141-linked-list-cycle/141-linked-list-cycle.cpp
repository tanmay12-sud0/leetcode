
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode* p = head;
        ListNode* q = head;
        
        while(q != NULL and q->next != NULL){
            p = p->next;
            q = q->next;
            q = q!=NULL ? q->next : q;
            if(q == p){
                return true;
            }
        }
        return false;
    }
};




// unorderd_map way to tackel this problem


// unordered_map<ListNode*, int>hash;
//         ListNode* p = head;
//         while(p != NULL){
//             if(hash.count(p)){
//                 return true;
//             }
//             hash[p]++;
//             p = p->next;
//         }
//         return false;
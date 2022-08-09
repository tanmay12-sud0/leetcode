class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, ListNode*>hash;
        ListNode* p = headA;
        ListNode* q = headB;
        while(p != NULL){
            hash[p] = p;
            p = p->next;
        }
        while(q != NULL){
            if(hash.count(q)){
                return hash[q];
            }
            q = q->next;
        }
        return NULL;
    }
};
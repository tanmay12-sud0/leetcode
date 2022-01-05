class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> >pq;
        int n = lists.size();
        for(int i=0; i<n; i++){
            ListNode* dummy = lists[i];
            if(dummy){
                pq.push(make_pair(lists[i]->val, dummy));
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(!pq.empty()){
            pair<int, ListNode*>pp = pq.top();
            pq.pop();
            // ListNode* x = new ListNode(pp.first);
            temp->next = pp.second;
            temp = pp.second;
            if(pp.second->next != NULL){
                pq.push(make_pair(pp.second->next->val, pp.second->next));
            }
        }
        return dummy->next;
    }
};
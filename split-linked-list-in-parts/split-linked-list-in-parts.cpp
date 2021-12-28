class Solution {
public:
    
    int len(ListNode* head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>hash;
        int lens = len(head);
        int diff = lens%k;
        int phase = lens/k;
        
        while(head != NULL){
            hash.push_back(head);
            int count = 0;
            ListNode* temp = NULL;
            while(count < phase){
                count++;
                temp = head;
                head = head->next;
            }
            
            if(diff>0){
                temp = head;
                head = head->next;
                diff--;
            }
            temp->next = NULL;
        }
        while(hash.size() != k){
            hash.push_back(NULL);
        }
        return hash;
    }
};
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
// class Solution {
// public:
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         if(head == NULL){
//             return NULL;
//         }
//         unordered_map<int, ListNode*>hash;
//         bool check = true;
//         int pre = 0;
//         while(check){
//             ListNode* temp = head;
//             check = false;
//         while(temp!=NULL){
//             pre += temp->val;
//             if(pre == 0){
//                 head = temp->next;
//                 hash.clear();
//                 check = true;
//                 break;
//             }
//             else if(hash.count(pre)){
//                 ListNode* l = hash[pre];
//                 l->next = temp->next;
//                 hash.clear();
//                 pre = 0;
//                 break;
//             }else{
//                 hash[pre] = temp;
//                 temp = temp->next;
//             }
            
//         }
//         }
//         return head;
//     }
// };




class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> nodes;
        int sum = 0;
        bool cont = true;
        while (cont) {
            cont = false;
            ListNode* temp = head;
            while (temp) {
                sum += temp->val;
                if (nodes.find(sum) != nodes.end()) {
                    ListNode* tail = nodes[sum];
                    tail->next = temp->next;
                    nodes.clear();
                    sum = 0;
                    cont = true;
                    break;
                } else if (sum == 0) {
                    head = temp->next;
                    nodes.clear();
                    cont = true;
                    break;
                } else {
                    nodes[sum] = temp;
                    temp = temp->next;
                }
            }
        }
        return head;
    }
};
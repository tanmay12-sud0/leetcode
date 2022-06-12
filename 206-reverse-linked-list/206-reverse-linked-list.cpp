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
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL or head->next == NULL){
//             return head;
//         }
//         ListNode* p = head;
//         ListNode* q = head->next;
//         ListNode* r = NULL;
//         while(p != NULL){
//             p->next = r;
//             r = p;
//             p = q;
//             q = q->next?q->next: NULL;
//         }
//         return r;
//     }
// };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
};
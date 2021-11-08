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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first2 = list2;
        ListNode* second2 = list2;
        while(second2->next != NULL){
            second2 = second2->next;
        }
       int count =1;
        ListNode* first1 = list1;
        while(count < a){
            first1 = first1->next;
            count++;
        }
        count =0;
        ListNode* second1 = list1;
        while(count <= b){
            second1 = second1->next;
            count++;
        }
        first1->next = first2;
        second2->next = second1;
        return list1;
        
    }
};
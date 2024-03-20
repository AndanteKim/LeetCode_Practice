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
        // Without sentinel or dummy
        ListNode *curr = list1;
        int count = 1;
        
        while (count < a){
            curr = curr -> next;
            ++count;
        }
        
        ListNode *insertAfter = curr;
        while (count < b + 1){
            curr = curr -> next;
            ++count;
        }
        
        insertAfter -> next = list2;
        ListNode *prev;
        while (list2){
            prev = list2;
            list2 = list2 -> next;
        }
        
        prev -> next = curr -> next;
        return list1;
    }
};
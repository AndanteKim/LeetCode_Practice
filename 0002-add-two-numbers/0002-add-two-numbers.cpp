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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Recursion : base case
        if (!(l1 || l2))
            return nullptr;
        else if (!l1 && l2)
            return l2;
        else if (l1 && !l2)
            return l1;
        
        ListNode* next = addTwoNumbers(l1 -> next, l2 -> next);
        int total = l1 -> val + l2 -> val;
        if (total >= 10){
            total %= 10;
            next = addTwoNumbers(next, new ListNode(1));
        }
        
        return new ListNode(total, next);
    }
};
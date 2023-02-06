/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> seen;
        
        while (head != nullptr){
            if (seen.find(head) != seen.end()) return true;
            seen.insert(head);
            head = head -> next;
        }
        return false;
    }
};
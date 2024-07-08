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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* curr = head;
        unordered_map<int, int> seen;
        
        while (curr){
            ++seen[curr -> val];
            curr = curr -> next;
        }
        
        ListNode* sentinel = new ListNode();
        sentinel -> next = head;
        ListNode* pred = sentinel;
        curr = head;
        
        while (curr){
            if (seen[curr -> val] >= 2)
                pred -> next = curr -> next;
            else
                pred = pred -> next;
            curr = curr -> next;
        }
        
        return sentinel -> next;
    }
};
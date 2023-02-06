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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode* first_node = head;
        ListNode* second_node = head -> next;
        
        first_node -> next = swapPairs(second_node -> next);
        second_node -> next = first_node;
        
        return second_node;
    }
};
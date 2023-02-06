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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = head;
        
        while (head != nullptr){
            ListNode *next_node = head -> next;
            while (next_node != nullptr && head -> val == next_node -> val){
                next_node = next_node -> next;
            }
            head -> next = next_node;
            head = head -> next;
        }
        
        return root;
    }
};
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
        
        ListNode* dummy = head -> next;
        ListNode* prev = nullptr;
        ListNode* next_Node;
        
        while (head != nullptr && head -> next != nullptr){
            if (prev != nullptr) prev -> next = head -> next;
            prev = head;
            
            next_Node = head -> next -> next;
            head -> next -> next = head;
            
            head -> next = next_Node;
            head = next_Node;
        }
        
        return dummy;
    }
};
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
    ListNode* end_of_first_half(ListNode* head){
        ListNode *slow = head, *fast = head;
        
        while (fast -> next != nullptr && fast -> next -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    ListNode* reverse_list(ListNode* head){
        ListNode *prev = nullptr, *curr = head;
        
        while (curr != nullptr){
            ListNode *next_node = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next_node;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        
        ListNode* first_half_end = end_of_first_half(head);
        ListNode* second_half_start = reverse_list(first_half_end -> next);
        
        bool result = true;
        ListNode* first_position = head, * second_position = second_half_start;
        
        while (result && second_position != nullptr){
            if (first_position -> val != second_position -> val) result = false;
            
            first_position = first_position -> next;
            second_position = second_position -> next;
        }
        first_half_end -> next = reverse_list(second_half_start);
        return result;
    }
};
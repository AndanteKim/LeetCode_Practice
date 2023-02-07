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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        
        int length = 0;
        ListNode *first = head;
        while (first != nullptr){
            ++length;
            first = first -> next;
        }
        
        length -= n;
        first = dummy;
        while (length > 0){
            --length;
            first = first -> next;
        }
        first -> next = first -> next -> next;
        
        return dummy -> next;
    }
};
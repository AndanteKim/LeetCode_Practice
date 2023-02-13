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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        int d = 2;
        
        while (prev -> next != nullptr){
            ListNode *node = prev;
            int n = 0;
            
            for (int i = 0; i < d; ++i){
                if (node -> next == nullptr) break;
                ++n;
                node = node -> next;
            }
            
            if (n & 1) prev = node;
            else{
                ListNode* rev = nullptr, *next_node;
                node = prev -> next;
                for (int i = 0; i < n; ++i){
                    next_node = node -> next;
                    node -> next = rev;
                    rev = node;
                    node = next_node;
                }
                next_node = prev -> next;
                prev -> next -> next = node;
                prev -> next = rev;
                prev = next_node;
            }
            ++d;
        }
        
        return head;
    }
};
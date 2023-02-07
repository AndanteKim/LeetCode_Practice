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
        if (head == nullptr) return nullptr;
        int i = 0, length = 0;
        ListNode *curr = new ListNode();
        curr -> next = head;
        
        while (curr != nullptr) {
            ++length;
            curr = curr -> next;
        }
        
        ListNode *root = new ListNode();
        root -> next = head;
        curr = root;
        
        while (i < length){
            if (i == length - n - 1) {
                curr -> next = curr -> next -> next;
                break;
            }
            curr = curr -> next;
            ++i;
        }
        
        return root -> next;
    }
};
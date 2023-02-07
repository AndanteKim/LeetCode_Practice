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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr){
            ++length;
            curr = curr -> next;
        }
        
        int i = 0, middle = (length / 2) - 1;
        curr = head;
        while (i < length){
            if (i == middle) {
                curr -> next = curr -> next -> next;
                break;
            }
            curr = curr -> next;
            ++i;
        }
        
        return head;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        // Base case
        if (!(head && head -> next)) return head;

        ListNode* oldTail = head;
        int n = 1;
        while (oldTail -> next) {
            oldTail = oldTail -> next;
            ++n;
        }

        oldTail -> next = head;
        ListNode* newTail = oldTail -> next;

        for (int i = 0; i < (n - k % n - 1); ++i) {
            newTail = newTail -> next;    
        }

        ListNode* newHead = newTail -> next;
        newTail -> next = nullptr;

        return newHead;
    }
};
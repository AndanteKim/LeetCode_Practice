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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // Reverse the second half of the LinkedList
        ListNode* curr = slow, *prev = nullptr;
        while (curr) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* start = head;
        int ans = 0;
        while (start && prev) {
            ans = max(ans, start -> val + prev -> val);
            start = start -> next;
            prev = prev -> next;
        }

        return ans;
    }
};
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
private:
    ListNode* rec(ListNode* head, int k){
        if (k == 0) return head;
        
        ListNode* curr = head, *prev = head;
        
        while (curr -> next){
            prev = curr;
            curr = curr -> next;
        }
        
        curr -> next = head;
        prev -> next = nullptr;
        head = curr;
        curr = prev;
        
        return rec(head, k - 1);
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Recursive approach
        if (!head) return head;

        ListNode *curr = head;
        int size = 0;
        
        while (curr){
            ++size;
            curr = curr -> next;
        }
        
        k %= size;
        return rec(head, k);
    }
};
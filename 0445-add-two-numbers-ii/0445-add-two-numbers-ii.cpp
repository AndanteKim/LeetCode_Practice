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
    ListNode* reverseList(ListNode* head){
        ListNode *prev = nullptr, *temp = nullptr;
        
        while (head){
            temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1 = reverseList(l1), *r2 = reverseList(l2);
        int digit = 0, carry = 0;
        ListNode *ans = new ListNode();
        while (r1 || r2){
            if (r1){
                digit += r1 -> val;
                r1 = r1 -> next;
            }
            if (r2){
                digit += r2 -> val;
                r2 = r2 -> next;
            }
            
            ans -> val = digit % 10;
            carry = digit / 10;
            ListNode *head = new ListNode(carry);
            head -> next = ans;
            ans = head;
            digit = carry;
        }
        
        return carry == 0? ans -> next : ans;
    }
};
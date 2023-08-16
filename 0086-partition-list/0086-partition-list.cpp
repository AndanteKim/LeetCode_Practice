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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head -> next) return head;
        
        head -> next = partition(head -> next, x);
        
        if (head -> val < x)
            return head;
        else{
            ListNode* curr = head;
            while (curr -> next){
                if (curr -> val > curr -> next -> val && curr -> next -> val < x){
                    int temp = curr -> val;
                    curr -> val = curr -> next -> val;
                    curr -> next -> val = temp;
                    curr = curr -> next;
                }
                else break;
            }
        }
        
        return head;
    }
};
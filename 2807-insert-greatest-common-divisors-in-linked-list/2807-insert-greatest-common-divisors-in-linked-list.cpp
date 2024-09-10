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
    int gcd(int a, int b){
        while (b > 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }
    
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* root = head;
        
        while (root && root -> next){
            root -> next = new ListNode(gcd(max(root -> val, root -> next -> val), min(root -> val, root -> next -> val)), \
                                       root -> next);
            root = root -> next -> next;
        }
        
        return head;
    }
};
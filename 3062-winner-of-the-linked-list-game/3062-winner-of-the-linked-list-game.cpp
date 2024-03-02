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
    string gameResult(ListNode* head) {
        int evenPt = 0, oddPt = 0;
        
        while (head && head -> next){
            int even = head -> val, odd = head -> next -> val;
            
            if (even < odd) ++oddPt;
            else ++evenPt;
            head = head -> next -> next;
        }
        
        return evenPt == oddPt? "Tie": (evenPt < oddPt)? "Odd": "Even"; 
    }
};
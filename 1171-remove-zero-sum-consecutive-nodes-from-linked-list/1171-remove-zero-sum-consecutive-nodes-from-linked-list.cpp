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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* curr = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        
        // Calculate the prefix sum for each node and add to the hashmap
        // Duplicate prefix sum values will be replaced
        while (curr){
            prefixSum += curr -> val;
            prefixSumToNode[prefixSum] = curr;
            curr = curr -> next;
        }
        
        // Reset prefix sum and current
        prefixSum = 0;
        curr = front;
        
        // Delete zero sum consecutive sequences
        // by setting node before sequence to node after
        while (curr){
            prefixSum += curr -> val;
            curr -> next = prefixSumToNode[prefixSum] -> next;
            curr = curr -> next;
        }
        
        return front -> next;
    }
};
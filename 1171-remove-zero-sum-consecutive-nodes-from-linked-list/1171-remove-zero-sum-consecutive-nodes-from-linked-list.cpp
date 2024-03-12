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
        
        while (curr){
            // Add current's value to the prefix sum
            prefixSum += curr -> val;
            
            // If prefixSum is already in the hashmap,
            // we have found a zero-sum sequence
            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()){
                ListNode* prev = prefixSumToNode[prefixSum];
                curr = prev -> next;
                
                // Delete zero sum nodes from hashmap
                // to prevent incorrect deletions from linked list
                int p = prefixSum + curr -> val;
                while (p != prefixSum){
                    prefixSumToNode.erase(p);
                    curr = curr -> next;
                    p += curr -> val;
                }
                prev -> next = curr -> next;
            }
            else
                // Add new prefixSum to hashmap
                prefixSumToNode[prefixSum] = curr;
            
            // Progress to next element inlist
            curr = curr -> next;
        }
        
        return front -> next;
    }
};
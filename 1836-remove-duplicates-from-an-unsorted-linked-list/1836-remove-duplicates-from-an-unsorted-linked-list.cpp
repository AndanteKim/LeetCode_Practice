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
    // Recursively delete duplicates based on the frequency map
    ListNode* deleteDuplicates(ListNode* head, unordered_map<int, int>& freq){
        // base case
        if (!head) return nullptr;
        
        // Recursive call for the next node
        ListNode* updatedNextNode = deleteDuplicates(head -> next, freq);
        
        head -> next = updatedNextNode;
        
        // If the current node is a duplicate, return the updated next node
        if (freq[head -> val] > 1)
            return updatedNextNode;
        
        // Otherwise, return the current node
        return head;
    }
    
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> freq;
        ListNode *curr = head;
        
        // Count the frequency of each value in the list
        while (curr){
            ++freq[curr -> val];
            curr = curr -> next;
        }
        
        return deleteDuplicates(head, freq);
    }
};
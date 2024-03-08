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
    ListNode* frequenciesOfElements(ListNode* head) {
        int maxVal = 100'000; // Maximum element value
        vector<int> freqs(maxVal);
        ListNode* curr = head;
        
        // Find the frequency of each element
        while (curr){
            ++freqs[curr -> val];
            curr = curr -> next;
        }
        
        ListNode *freqHead = new ListNode();
        curr = freqHead;
        
        // Create a linked list of the frequencies of the elements
        for (int i = 0; i < maxVal; ++i){
            if (freqs[i] > 0){
                curr -> next = new ListNode(freqs[i]); 
                curr = curr -> next;
            }
        }
        
        return freqHead -> next;
    }
};
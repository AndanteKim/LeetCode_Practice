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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans{-1, -1};
        
        // Pointers to track the previous node, current node, and indices
        ListNode* curr = head -> next, *prev = head;
        int prevCriticalIdx = 0, currIdx = 1, firstCriticalIdx = 0;
        
        // Intialize minimum distance to the maximum possible value
        int minDist = INT_MAX;
        
        while (curr -> next){
            // Check if the current node is a local maxima or minima
            if ((curr -> val < prev -> val && curr -> val < curr -> next -> val)\
                || (curr -> val > prev -> val && curr -> val > curr -> next -> val)){
                
                // If this is the first critical point found
                if (firstCriticalIdx == 0){
                    firstCriticalIdx = currIdx;
                    prevCriticalIdx = currIdx;
                }
                else{
                    // Calculate the minimum distance between critical points
                    minDist = min(minDist, currIdx - prevCriticalIdx);
                    prevCriticalIdx = currIdx;
                }
            }
            
            // Move to the next node and update indices
            prev = curr;
            curr = curr -> next;
            ++currIdx;
        }
        
        // If at least two critical points were found
        if (minDist != INT_MAX){
            ans[0] = minDist;
            ans[1] = prevCriticalIdx - firstCriticalIdx;
        }
        
        return ans;
    }
};
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
        if (!head) return {-1, -1};
        
        vector<int> merged;
        ListNode *curr = head -> next, *prev = head;
        int i = 2;
        
        while (curr -> next){
            // If it's local minima
            if ((curr -> val < prev -> val && prev -> val <= curr -> next -> val) || (curr -> val < curr -> next -> val\
                                                                                     && curr -> next -> val <= prev -> val))
                merged.push_back(i);
            
            // If it's local maxima
            else if ((curr -> val > prev -> val && prev -> val >= curr -> next -> val) || (curr -> val > curr -> next -> val\
                                                                                          && curr -> next -> val >= prev -> val))
                merged.push_back(i);
            
            curr = curr -> next;
            prev = prev -> next;
            ++i;
        }
      
        if (merged.size() < 2)
            return {-1, -1};
        
        vector<int> ans{INT_MAX, merged.back() - merged[0]};
        
        for (int k = 0; k < merged.size() - 1; ++k)
            ans[0] = min(ans[0], merged[k + 1] - merged[k]);
        
        return ans;
    }
};
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* root = head;
        int left = 0, right = n, up = 0, down = m;
        bool noHead = false;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        // Traverse the spiral
        while ((left < right || up < down) && !noHead){
            // From the left to the right
            for (int c = left; c < right; ++c){
                if (!root){
                    noHead = true;
                    break;
                }
                
                ans[up][c] = root -> val;
                root = root -> next;
            }
            
            ++up;
            if (noHead) break;
            
            // From the up to the down
            for (int r = up; r < down; ++r){
                if (!root){
                    noHead = true;
                    break;
                }
                
                ans[r][right - 1] = root -> val;
                root = root -> next;
            }
            --right;
            if (noHead) break;
            
            // From right - 1 to the left
            for (int c = right - 1; c > left - 1; --c){
                if (!root){
                    noHead = true;
                    break;
                }
                
                ans[down - 1][c] = root -> val;
                root = root -> next;
            }
            
            --down;
            if (noHead) break;
            
            // From down - 1 to the up
            for (int r = down - 1; r >= up; --r){
                if (!root){
                    noHead = true;
                    break;
                }
                
                ans[r][left] = root -> val;
                root = root -> next;
            }
            ++left;
            if (noHead) break;
        }
        
        return ans;
    }
};
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
        // Store the direction starting east, south, west, north movements in a matrix sequentially.
        int i = 0, j = 0, currDirection = 0;
        vector<pair<int, int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        while (head){
            matrix[i][j] = head -> val;
            
            int row = i + direction[currDirection].first, col = j + direction[currDirection].second;
            
            // If we bump into an edge or an already filled cell, change the direction.
            if (min(row, col) < 0 || row >= m || col >= n || matrix[row][col] != -1)
                currDirection = (currDirection + 1) % 4;
            i += direction[currDirection].first;
            j += direction[currDirection].second;
            
            head = head -> next;
        }
        
        return matrix;
    }
};
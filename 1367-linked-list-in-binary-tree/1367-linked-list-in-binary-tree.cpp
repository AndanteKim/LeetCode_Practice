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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool searchInTree(TreeNode* node, int patternIndex, vector<int>& pattern, vector<int>& prefixTable){
        if (!node)
            return false;
        
        while (patternIndex > 0 && pattern[patternIndex] != node -> val)
            patternIndex = prefixTable[patternIndex - 1];
        (pattern[patternIndex] == node -> val)? ++patternIndex : patternIndex = 0;
        
        // Check if the pattern is fully matched
        if (patternIndex == pattern.size())
            return true;
        
        // Recursively search left and right subtrees
        return searchInTree(node -> left, patternIndex, pattern, prefixTable) || searchInTree(node -> right, patternIndex, pattern, prefixTable);
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // Build the pattern and prefix table from the linked list
        vector<int> pattern{head -> val}, prefixTable{0};
        head = head -> next;
        int patternIndex = 0;
        
        while (head){
            while (patternIndex > 0 && pattern[patternIndex] != head -> val)
                patternIndex = prefixTable[patternIndex - 1];
            
            (pattern[patternIndex] == head -> val)? ++patternIndex : patternIndex = 0;
            pattern.push_back(head -> val);
            prefixTable.push_back(patternIndex);
            head = head -> next;
        }
        
        // Perform DFS to search for the pattern in the tree.
        return searchInTree(root, 0, pattern, prefixTable);
    }
};
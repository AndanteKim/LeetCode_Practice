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
    vector<int> mapListToValues(ListNode* head){
        vector<int> vals;
        while (head){
            vals.push_back(head -> val);
            head = head -> next;
        }
        return vals;
    }
    
    TreeNode* convertListToBST(vector<int>& values, int left, int right){
        if (left > right) return nullptr;
        int mid = (left + right) >> 1;
        TreeNode* node = new TreeNode(values[mid]);
        
        if (left == right) return node;
        node -> left = convertListToBST(values, left, mid - 1);
        node -> right = convertListToBST(values, mid + 1, right);
        
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> values = mapListToValues(head);
        return convertListToBST(values, 0, values.size() - 1);
    }
};
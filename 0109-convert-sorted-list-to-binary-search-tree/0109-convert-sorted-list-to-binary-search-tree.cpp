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
    ListNode* head;
    
    int findSize(ListNode* head){
        ListNode *ptr = head;
        int c = 0;
        while (ptr){
            ++c;
            ptr = ptr -> next;
        }
        return c;
    }
    
    TreeNode* convert(int left, int right){
        if (left > right) return nullptr;
        
        int mid = (left + right) >> 1;
        
        TreeNode* Left_node = convert(left, mid - 1);
        TreeNode* node = new TreeNode(this -> head -> val);
        node -> left = Left_node;
        this -> head = this -> head -> next;
        node -> right = convert(mid + 1, right);
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this -> head = head;
        int s = findSize(this -> head);
        return convert(0, s - 1);
    }
};
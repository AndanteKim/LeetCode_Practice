/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> *seen = new set<ListNode*>;
        ListNode* root = head;
        
        while (root != nullptr && root -> next != nullptr){
            if (seen -> find(root) == seen -> end()){
                seen -> insert(root);
            }
            else{
                return root;
            }
            root = root -> next;
        }
        
        return nullptr;
    }
};
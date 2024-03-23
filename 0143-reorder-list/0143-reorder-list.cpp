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
    ListNode* reorderList(ListNode* root, ListNode* curr){
        if (!curr)
            return root;
        
        // Keep on passing the initial root to the end
        root = reorderList(root, curr -> next);
        
        if (!root)
            return nullptr;
        /*
        We stop reconfiguring in 2 cases
        1. returned new root is same as head: odd number of list items, so we have come to the middle
        
        2. returned new root's next is same as head: Even number of list nums
        */
        ListNode *temp = nullptr;
        if (root == curr || root -> next == curr){
            curr -> next = nullptr;
        }
        else{
            // Make returned root's next to be curr and return root's next as the new root
            temp = root -> next;
            root -> next = curr;
            curr -> next = temp;
        }
        
        return temp;
    }
    
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        
        reorderList(head, head -> next);
    }
};
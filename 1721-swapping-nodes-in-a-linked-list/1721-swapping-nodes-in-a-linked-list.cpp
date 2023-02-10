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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* currNode = head;
        ListNode* frontNode, *endNode;
        
        while (currNode != nullptr){
            ++length;
            currNode = currNode -> next;
        }
        frontNode = head;
        for (int i = 0; i < k - 1; ++i){
            frontNode = frontNode -> next;
        }
        
        
        endNode = head;
        for(int i = 0; i < length - k; ++i){
            endNode = endNode -> next;
        }
        
        swap(frontNode -> val, endNode -> val);
        
        return head;
    }
};
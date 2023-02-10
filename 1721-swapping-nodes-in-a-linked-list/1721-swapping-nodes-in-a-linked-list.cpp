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
        
        ListNode* frontNode = nullptr, *endNode = nullptr;
        ListNode* currNode = head;
        
        while (currNode != nullptr){
            ++length;
            if (endNode != nullptr) endNode = endNode -> next;
            if (length == k){
                frontNode = currNode;
                endNode = head;
            }
            currNode = currNode -> next;
        }
        
        swap(frontNode -> val, endNode -> val);
        return head;
    }
};
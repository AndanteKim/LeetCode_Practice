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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* currNode = head, *lastMNode = head;

        while (currNode){
            // Intialize mCount to m and nCount = n
            int mCount = m, nCount = n;
            
            // traverse m nodes
            while (currNode && mCount > 0){
                lastMNode = currNode;
                currNode = currNode -> next;
                --mCount;
            }

            // traverse n nodes
            while (currNode && nCount > 0){
                currNode = currNode -> next;
                --nCount;
            }

            // delete n nodes
            lastMNode -> next = currNode;
        }

        return head;
    }
};
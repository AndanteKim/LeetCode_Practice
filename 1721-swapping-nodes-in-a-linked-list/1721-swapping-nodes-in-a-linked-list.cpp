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
    void swapListNodesToNext(ListNode* prevOfFirstK, ListNode* prevOfLastK){
        if (prevOfLastK -> next == prevOfFirstK) swapListNodesToNext(prevOfLastK, prevOfFirstK);
        else if (prevOfFirstK -> next == prevOfLastK){
            prevOfFirstK -> next = prevOfLastK -> next;
            prevOfLastK -> next = prevOfFirstK -> next -> next;
            prevOfFirstK -> next -> next = prevOfLastK;
        }
        else{
            ListNode *tempLeftNextNext = prevOfFirstK -> next -> next;
            ListNode *tempRightNextNext = prevOfLastK -> next -> next;
            ListNode *tempLeftNext = prevOfFirstK -> next;
            prevOfFirstK -> next = prevOfLastK -> next;
            prevOfFirstK -> next -> next = tempLeftNextNext;
            prevOfLastK -> next = tempLeftNext;
            prevOfLastK -> next -> next = tempRightNextNext;
        }
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* sentinel = new ListNode(-1);
        sentinel -> next = head;
        ListNode* last = sentinel;
        
        for (int i = 0; i < k - 1; ++i) last = last -> next;
        
        ListNode* prevOfFirstK = last, *prevOfLastK = sentinel;
        
        while (last -> next -> next != nullptr){
            last = last -> next;
            prevOfLastK = prevOfLastK -> next;
        }
        
        swapListNodesToNext(prevOfFirstK, prevOfLastK);
        
        return sentinel -> next;
    }
};
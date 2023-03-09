/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *getIntersect(ListNode *head){
        ListNode *hare = head, *tortoise = head;
        
        while (hare && hare -> next){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
            if (tortoise == hare) return tortoise;
        }
        
        return nullptr;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        
        ListNode* intersect = getIntersect(head);
        
        if (!intersect) return nullptr;
        
        ListNode* ptr1 = head, *ptr2 = intersect;
        
        while(ptr1 != ptr2){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        return ptr1;
    }
};
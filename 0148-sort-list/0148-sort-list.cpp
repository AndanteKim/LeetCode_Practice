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
    ListNode* getMid(ListNode* head){
        ListNode* midPrev = nullptr;
        
        while (head && head -> next){
            midPrev = (midPrev == nullptr)? head : midPrev -> next;
            head = head -> next -> next; 
        }
        
        ListNode* mid = midPrev -> next;
        midPrev -> next = nullptr;
        return mid;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode *dummy = new ListNode(), *curr = dummy;
        while (list1 && list2){
            if (list1 -> val < list2 -> val){
                curr -> next = list1;
                list1 = list1 -> next;
            }
            else{
                curr -> next = list2;
                list2 = list2 -> next;
            }
            
            curr = curr -> next;
        }
        curr -> next = list1? list1 : list2;
        
        return dummy -> next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        // Top down style
        // Base case: If the head or the entire list is none, return the head.
        if (!head || !head -> next)
            return head;
        
        // Get the middle node
        ListNode* mid = getMid(head);
        
        // Split the list to left and right and sort them
        ListNode* left = sortList(head), *right = sortList(mid);
        
        // Merge the sorted lists
        return merge(left, right);
    }
};
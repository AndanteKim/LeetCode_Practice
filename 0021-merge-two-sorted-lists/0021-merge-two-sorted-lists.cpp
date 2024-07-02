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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sentinel = new ListNode();
        ListNode* curr = sentinel;
        
        // Running until both list1 and list2 are exhausted(equal to nullptr)
        while (list1 || list2){
            if (list1 && list2){
                if (list1 -> val >= list2 -> val){
                    curr -> next = list2;
                    list2 = list2 -> next;
                }
                else{
                    curr -> next = list1;
                    list1 = list1 -> next;
                }
            }
            else if (list1){
                curr -> next = list1;
                list1 = list1 -> next;
            }
            else{
                curr -> next = list2;
                list2 = list2 -> next;
            }
            
            // Move to the next pointer
            curr = curr -> next;
        }
        
        return sentinel -> next;
    }
};
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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode();
        ListNode* point = head;
        
        while (l1 != nullptr && l2 != nullptr){
            if (l1 -> val <= l2 -> val){
                point -> next = l1;
                l1 = l1 -> next;
            }
            else{
                point -> next = l2;
                l2 = l1;
                l1 = point -> next -> next;
            }
            point = point -> next;
        }
        
        if (l1 == nullptr) point -> next = l2;
        else point -> next = l1;
        
        return head -> next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size(), interval = 1;
        
        while (interval < amount){
            for (int i = 0; i < amount - interval; i += interval * 2){
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return amount > 0? lists[0] : NULL;
    }
};
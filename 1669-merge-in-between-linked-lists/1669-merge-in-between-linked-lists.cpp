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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *sentinel = new ListNode(), *l2 = list2, *root = sentinel;
        sentinel -> next = list1;
        int curr = -1;
        
        while (root){
            // remove list1 starting from a
            if (curr == a - 1){
                ListNode *temp = root -> next;
                root -> next = list2;
                root = temp;
            }
            
            // reconnect list starting from b + 1
            if (curr == b){
                while (l2 -> next){
                    l2 = l2 -> next;
                }
                l2 -> next = root;
            }
            
            root = root -> next;
            ++curr;
        }
        
        return sentinel -> next;
    }
};
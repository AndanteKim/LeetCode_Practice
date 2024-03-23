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
    void reorderList(ListNode* head) {
        ListNode *front = head, *mid = head;
        stack<ListNode*> s;
        int i = 0;
        
        if (!(front && front -> next)) return;
        
        while (front && front -> next){
            ++i;
            mid = mid -> next;
            front = front -> next -> next;
        }
        
        while (mid){
            s.push(mid);
            ++i;
            mid = mid -> next;
        }
        
        front = head;
        while (!s.empty()){
            ListNode *temp = front -> next, *rear = s.top();
            s.pop();
            front -> next = rear;
            rear -> next = temp;
            front = temp;
        }
        
        if (i % 2) front -> next -> next = nullptr;
        else front -> next = nullptr;
    }
};
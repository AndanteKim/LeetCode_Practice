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
    bool stop = false;
    ListNode *left_head;
    void recurseAndReverse(ListNode* right_head, int m, int n){
        if (n == 1) return;
        
        right_head = right_head -> next;
        if (m > 1) this -> left_head = this -> left_head -> next;
        recurseAndReverse(right_head, m - 1, n - 1);
        if (this -> left_head == right_head || right_head -> next == this -> left_head) this -> stop = true;
        
        if (!stop){
            swap(this -> left_head -> val, right_head -> val);
            this -> left_head = this -> left_head -> next;
        }
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return nullptr;
        ListNode *right_head = head;
        this -> left_head = head;
        recurseAndReverse(right_head, left, right);
        return head;
    }
};
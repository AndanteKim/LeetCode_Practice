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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> freqs;
        ListNode* root = head;
        int k = 0;
        vector<int> keys;
        while (root){
            if (freqs[root -> val] == 0){
                keys.push_back(root -> val);
                ++k;
            }
            ++freqs[root -> val];
            root = root -> next;
        }
        
        ListNode* sentinel = root = new ListNode(); 
        while (k-- > 0){
            root -> next = new ListNode(freqs[keys.back()]);
            freqs.erase(keys.back());
            keys.pop_back();
            root = root -> next;
        }
        
        return sentinel -> next;
    }
};
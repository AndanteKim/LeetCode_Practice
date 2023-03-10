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
    vector<int> range;
public:
    Solution(ListNode* head) {
        while (head != nullptr){
            range.push_back(head -> val);
            head = head -> next;
        }
        
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0, 1.0);
        int pick = int(dis(gen) * range.size());
        return range[pick];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
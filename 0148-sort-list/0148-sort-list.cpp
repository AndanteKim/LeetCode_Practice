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
    ListNode* tail = new ListNode();
    ListNode* nextSublist = new ListNode();
    
    int getCount(ListNode* head){
        int count = 0;
        
        while (head){
            ++count;
            head = head -> next;
        }
        
        return count;
    }
    
    ListNode* split(ListNode* start, int size){
        ListNode* midPrev = start;
        ListNode* end = start -> next;
        
        // Use fast and slow approach to find middle and end of the second linked list
        for (int index = 1; index < size && (midPrev -> next || end -> next); ++index){
            if (end -> next)
                end = (end -> next -> next)? end -> next -> next : end -> next;
            
            if (midPrev -> next)
                midPrev = midPrev -> next;
        }
        
        ListNode* mid = midPrev -> next;
        nextSublist = end -> next;
        midPrev -> next = nullptr;
        end -> next = nullptr;
        
        // return the start of the second linked list
        return mid;
    }
    
    void merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* newTail = dummy;
        
        while (list1 && list2){
            if (list1 -> val < list2 -> val){
                newTail -> next = list1;
                list1 = list1 -> next;
            }
            else{
                newTail -> next = list2;
                list2 = list2 -> next;
            }
            
            newTail = newTail -> next;
        }
        
        newTail -> next = (list1)? list1 : list2;
        
        // Traverse till the end of merged list to get the newTail
        while (newTail -> next)
            newTail = newTail -> next;
        
        // Link the old tail with the head of merged list
        tail -> next = dummy -> next;
        
        // Update the old tail with the new tail of merged list
        tail = newTail;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!(head && head -> next)) return head;
        
        int n = getCount(head);
        ListNode* dummy = new ListNode(), *start = head;
        
        for (int size = 1; size < n; size *= 2){
            tail = dummy;
            
            while (start){
                if (!start -> next){
                    tail -> next = start;
                    break;
                }
                
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextSublist;
            }
            
            start = dummy -> next;
        }
        
        return dummy -> next;
    }
};
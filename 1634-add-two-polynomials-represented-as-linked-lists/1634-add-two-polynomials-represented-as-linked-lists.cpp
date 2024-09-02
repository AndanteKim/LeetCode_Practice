/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* p1 = poly1, *p2 = poly2;
        
        // Initialize the dummy node and maintain pointer to last node
        PolyNode* dummy = new PolyNode(), *curr = dummy;
        
        // Maintain two pointers
        while (p1 && p2){
            if (p1 -> power == p2 -> power){
                if (p1 -> coefficient + p2 -> coefficient != 0){
                    curr -> next = new PolyNode(p1 -> coefficient + p2 -> coefficient, p1 -> power);
                    curr = curr -> next;
                }
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
            else if (p1 -> power > p2 -> power){
                curr -> next = new PolyNode(p1 -> coefficient, p1 -> power);
                p1 = p1 -> next;
                curr = curr -> next;
            }
            else{
                curr -> next = new PolyNode(p2 -> coefficient, p2 -> power);
                p2 = p2 -> next;
                curr = curr -> next;
            }
        }
        
        if (p1) curr -> next = p1;
        else curr -> next = p2;
        
        return dummy -> next;
    }
};
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
private:
    void processNode(map<int, int, greater<int>>& table, PolyNode* poly){
        PolyNode* node = poly;
        while (node){
            if (table.count(node -> power)){
                int newCoefficient = table[node -> power] + node -> coefficient;
                if (newCoefficient == 0)
                    table.erase(node -> power);
                else
                    table[node -> power] = newCoefficient;
            }
            else
                table[node -> power] = node -> coefficient;
                
            node = node -> next;
        }
    }
    
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* sum = new PolyNode();
        PolyNode* curr = sum;
        
        map<int, int, greater<int>> table;
        
        // Calculate terms for sum
        processNode(table, poly1);
        processNode(table, poly2);
        
        // Iterate over sorted keys and build sum
        for (auto& [key, val] : table){
            curr -> next = new PolyNode(val, key);
            curr = curr -> next;
        }
        
        return sum -> next;
    }
};
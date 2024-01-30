class Solution {
private:
    void delete2AtIndex(vector<string>& tokens, int d, int length){
        for (int i = d; i < length - 2; ++i)
            tokens[i] = tokens[i + 2];
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operations;
        operations["+"] = [](int a, int b) -> int{
            return a + b;
        };
        operations["-"] = [](int a, int b) -> int{
            return a - b;
        };
        operations["*"] = [](int a, int b) -> int{
            return a * b;
        };
        operations["/"] = [](int a, int b) -> int{
            return a / b;
        };
        
        int currPos = 0, length = tokens.size();
        while (length > 1){
            
            // Move the current position and numbers from the list
            while (operations.find(tokens[currPos]) == operations.end())
                ++currPos;
            
            // Extract the operator and numbers from the list.
            string opr = tokens[currPos];
            int n1 = stoi(tokens[currPos - 2]), n2 = stoi(tokens[currPos - 1]);
            
            // Calculate the result to overwrite the operator with.
            tokens[currPos] = to_string(operations[opr](n1, n2));
            
            // Remove the numbers and move the pointer to the position
            // after the new number we just added.
            delete2AtIndex(tokens, currPos - 2, length);
            --currPos;
            length -= 2;
        }
        
        return stoi(tokens[0]);
    }
};
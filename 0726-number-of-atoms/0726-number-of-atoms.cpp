class Solution {
public:
    string countOfAtoms(string formula) {
        // Stack to keep track of the atoms and their counts
        stack<map<string, int>> stk;
        stk.push(map<string, int> ());
        
        // Index to keep track of the current character.
        int index = 0, n = formula.size();
        
        while (index < n){
            // If left parentheses, insert a new hashmp to the stack. It will
            // keep track of the atoms and their counts in the nested formula.
            if (formula[index] == '('){
                stk.push(map<string, int> ());
                ++index;
            }
            
            // Right parentheses, pop the top element from the stack.
            // Multiply the count with the multiplicity of the nested formula.
            else if (formula[index] == ')'){
                map<string, int> currMap = stk.top(); stk.pop();
                string multiplier = "";
                ++index;
                
                while (index < n && isdigit(formula[index])){
                    multiplier += formula[index++];
                }
                
                if (!multiplier.empty()){
                    int mult = stoi(multiplier);
                    for (auto& [atom, _] : currMap)
                        currMap[atom] *= mult;
                }
                
                for (auto& [atom, count] : currMap)
                    stk.top()[atom] += count;
            }
            // Otherwise, it must be a upper letter. Extract the complete
            // atom with frequency, and update the most recent hashmap.
            else{
                string currAtom;
                currAtom += formula[index++];
                
                while (index < n && islower(formula[index]))
                    currAtom += formula[index++];
                
                string currCnt = "";
                while (index < n && isdigit(formula[index]))
                    currCnt += formula[index++];
                
                if (currCnt.empty()){
                    ++stk.top()[currAtom];
                }
                else stk.top()[currAtom] += stoi(currCnt);
            }
            
        }
        
        string ans = "";
        for (auto& [atom, val] : stk.top()){
            ans += atom;
            if (val > 1)
                ans += to_string(val);
        }
        
        return ans;
    }
};
class Solution {
public:
    string countOfAtoms(string formula) {
        // For every index, store the valid multiplier
        int runningMul = 1;
        vector<int> muls(formula.size());
        
        // Stack to take care of nested formula
        stack<int> st;
        st.push(1);
        
        // Preprocess the formula and extract all multipliers
        string currNum = "";
        for (int i = formula.size() - 1; i >= 0; --i){
            if (isdigit(formula[i])) currNum = formula[i] + currNum;
            
            // If we encountered a letter, then the scanned
            // number was count and not a multiplier. Discard it.
            else if (isalpha(formula[i])) currNum = "";
            
            // If we encounter a right parenthesis, then the
            // scanned number was multiplier. Store it.
            else if (formula[i] == ')'){
                int currMultiplier = (!currNum.empty())? stoi(currNum) : 1;
                runningMul *= currMultiplier;
                st.push(currMultiplier);
                currNum.clear();
            }
            
            // If we encounter a left parenthesis, then the
            // most recent multiplier will cease to exist.
            else if (formula[i] == '('){
                runningMul /= st.top();
                st.pop();
                currNum.clear();
            }
            muls[i] = runningMul;
        }
        
        
        int i = 0;
        // Map to store the count of atoms
        map<string, int> finalMap;
        
        // Traverse left to right in the formula
        while (i < formula.size()){
            // If upper case letter, extract the entire atom
            if (isupper(formula[i])){
                string currAtom = "", currCount = "";
                currAtom.push_back(formula[i]);
                ++i;
                
                while (i < formula.size() && islower(formula[i])){
                    currAtom += formula[i];
                    ++i;
                }
                
                // Extract the count
                while (i < formula.size() && isdigit(formula[i])){
                    currCount += formula[i];
                    ++i;
                }
                
                // Update the final map
                int count = currCount.empty()? 1: stoi(currCount);
                finalMap[currAtom] += count * muls[i - 1];
            }
            else
                ++i;
        }
        
        // Generate the answer string
        string ans = "";
        for (auto& [atom, val] : finalMap){
            ans += atom;
            if (val > 1)
                ans += to_string(val);
        }
        
        return ans;
    }
};
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Stack to keep track of the atoms and their counts
        stack = [defaultdict(int)]
        
        # Index to keep track of the current character
        index = 0
        
        # Parse the formula
        while index < len(formula):
            # If left parenthesis, insert a new hashmap to the staxk. It will
            # keep track of the atoms and their counts in the nested formula
            if formula[index] == '(':
                stack.append(defaultdict(int))
                index += 1
                
            # If right parenthesis, pop the top element from the stack
            # Multiply the count with the multiplicity of the nested formula
            elif formula[index] == ')':
                curr_map = stack.pop()
                index += 1
                
                multiplier = ""
                while index < len(formula) and formula[index].isdigit():
                    multiplier += formula[index]
                    index += 1
                      
                if multiplier:
                    multiplier = int(multiplier)
                    for atom in curr_map:
                        curr_map[atom] *= multiplier
                        
                for atom in curr_map:
                    stack[-1][atom] += curr_map[atom]
                    
            # Otherwise, it must be a upper letter. Extract the complete
            # atom with frequency, and update the most recent hashmap.
            else:
                curr_atom = formula[index]
                index += 1
                
                while index < len(formula) and formula[index].islower():
                    curr_atom += formula[index]
                    index += 1
                
                curr_cnt = ""
                while index < len(formula) and formula[index].isdigit():
                    curr_cnt += formula[index]
                    index += 1
                    
                if curr_cnt == "":
                    stack[-1][curr_atom] += 1
                else:
                    stack[-1][curr_atom] += int(curr_cnt)
                    
        # Sort the final map
        final_map = dict(sorted(stack[0].items()))
        
        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])
                
        return ans
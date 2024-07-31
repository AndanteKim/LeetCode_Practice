class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # For every index, store the valid multiplier
        muls, running_mul = [], 1
        
        # Stack to take care of nested formula
        stack = [1]
        
        # Preprocess the formula and extract all multipliers
        curr_num = ""
        for i in range(len(formula) - 1, -1, -1):
            if formula[i].isdigit():
                curr_num += formula[i]
                
            # If we encountered a letter, then the scanned
            # number was count and not multiplier. Discard it.
            elif formula[i].isalpha():
                curr_num = ""
                
            # If we encounter a right parenthesis, then the
            # scanned number was a multiplier. Store it.
            elif formula[i] == ')':
                curr_multiplier = int(curr_num[::-1]) if curr_num else 1
                running_mul *= curr_multiplier
                stack.append(curr_multiplier)
                curr_num = ""
                
            # If we encounter a left parenthesis, then the
            # most recent multiplier will cease to exist.
            elif formula[i] == '(':
                running_mul //= stack.pop()
                curr_num = ""
                
            # For every index, store the valid multiplier
            muls.append(running_mul)
            
        # Reverse the muls
        muls = muls[::-1]
        
        # Map to store the count of atoms
        final_map = defaultdict(int)
        
        # Traverse left to right in the formula
        i = 0
        while i < len(formula):
            # If upper case letter, extract the entire atom
            if formula[i].isupper():
                curr_atom = formula[i]
                curr_count = ""
                i += 1
                
                while i < len(formula) and formula[i].islower():
                    curr_atom += formula[i]
                    i += 1
                  
                # Extract the count
                while i < len(formula) and formula[i].isdigit():
                    curr_count += formula[i]
                    i += 1
                
                # Update the final map
                if curr_count:
                    final_map[curr_atom] += int(curr_count) * muls[i - 1]
                else:
                    final_map[curr_atom] += 1 * muls[i - 1]
                    
            else:
                i += 1
                
        # Sort the final map
        final_map = dict(sorted(final_map.items()))
        
        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])
                
        return ans
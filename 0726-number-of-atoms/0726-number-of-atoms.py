class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # For multipliers
        stack, running_mul = [1], 1
        
        # Map to store the count of atoms
        final_map = defaultdict(int)
        
        # Strings to take care of current atom and count
        curr_atom, curr_count = "", ""
        
        # Index to traverse the formula in reverse and parse the formula
        for index in range(len(formula) - 1, -1, -1):
            # If digit, update the count
            if formula[index].isdigit():
                curr_count = formula[index] + curr_count
                
            # If lowercase letter, prepend to the curr_atom
            elif formula[index].islower():
                curr_atom = formula[index] + curr_atom
                
            # If uppercase letter, prepend and update the finalMap
            elif formula[index].isupper():
                curr_atom = formula[index] + curr_atom
                
                if curr_count:
                    final_map[curr_atom] += int(curr_count) * running_mul
                else:
                    final_map[curr_atom] += 1 * running_mul
                    
                curr_atom, curr_count = "", ""
                
            # If the right parenthesis, the curr_count if any
            # will be considered a multiplier
            elif formula[index] == ')':
                curr_multiplier = int(curr_count) if curr_count else 1
                stack.append(curr_multiplier)
                running_mul *= curr_multiplier
                curr_count = ""
                
            # If left parenthesis, update the running_mul
            elif formula[index] == '(':
                running_mul //= stack.pop()
                
        final_map = dict(sorted(final_map.items()))
        
        ans = ""
        for atom, val in final_map.items():
            ans += atom
            if val > 1:
                ans += str(val)
        
        return ans
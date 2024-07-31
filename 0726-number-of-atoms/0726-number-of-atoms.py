class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Every element of matcher will be a quintuple
        matcher = re.findall(r"([A-Z][a-z]*)(\d*)|(\()|(\))(\d*)", formula)
        matcher.reverse()
        
        # Map to store the count of atoms
        final_map = defaultdict(int)
        
        # Stack to keep track of the nested multiplicities
        stack = [1]
        
        # Current multiplicity
        running_mul = 1
        
        # Parse the formula
        for atom, count, left, right, multiplier in matcher:
            # If atom, add it to the final map
            if atom:
                if count:
                    final_map[atom] += int(count) * running_mul
                else:
                    final_map[atom] += 1 * running_mul
                    
            # If the right parenthesis, multiply the running_mul
            elif right:
                if not multiplier:
                    multiplier = 1
                else:
                    multiplier = int(multiplier)
                    
                running_mul *= multiplier
                stack.append(multiplier)
            
            # If left parenthesis, divide the running_mul
            elif left:
                running_mul //= stack.pop()
                
        # Sort the final map
        final_map = dict(sorted(final_map.items()))
        
        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])
                
        return ans
        
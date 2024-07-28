class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Regular expression to extract atom, count, (, ), multiplier
        # Every element of matcher will be a quintuplea
        regex = r"([A-Z][a-z]*)(\d*)|(\()|(\))(\d*)"
        matcher = re.findall(regex, formula)
        
        # Stack to keep track of the atoms and their counts
        stack = [defaultdict(int)]
        
        print(matcher)
        # Parse the formula
        for atom, count, left, right, multiplier in matcher:
            # If atom, add it to the top hashmap
            if atom:
                stack[-1][atom] += int(count) if count else 1
                
            # If left parenthesis, insert a new hashmap to the stack
            elif left:
                stack.append(defaultdict(int))
                
            # If right parenthesis, pop the top element from the stack
            # Multiply the count with the attached multiplicity.
            # Add the count to the current formula
            elif right:
                curr_map = stack.pop()
                if multiplier:
                    multiplier = int(multiplier)
                    for atom in curr_map:
                        curr_map[atom] *= multiplier
                    
                for atom in curr_map:
                    stack[-1][atom] += curr_map[atom]
                    
        # Sort the final map
        final_map = dict(sorted(stack[0].items()))
        
        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])
                
        return ans
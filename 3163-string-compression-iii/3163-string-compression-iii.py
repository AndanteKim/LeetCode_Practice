class Solution:
    def compressedString(self, word: str) -> str:
        # Pos tracks our position in the input string
        comp, pos = [], 0
        
        # Process until we reach end of string
        while pos < len(word):
            consec_cnt = 0
            curr_ch = word[pos]
            
            # Count consecutive occurrences (maximum 9)
            while (pos < len(word) and consec_cnt < 9 and word[pos] == curr_ch):
                consec_cnt += 1
                pos += 1
                
            # Append count followed by character to the list
            comp.append(str(consec_cnt))
            comp.append(curr_ch)
            
        # Join the list into a single string for the final result
        return "".join(comp)
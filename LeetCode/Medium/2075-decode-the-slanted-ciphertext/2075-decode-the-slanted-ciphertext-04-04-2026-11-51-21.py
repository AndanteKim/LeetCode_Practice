class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        # Base case
        if rows == 1:
            return encodedText

        n = len(encodedText)
        ans, cols = [], n // rows
        
        for c in range(cols):            
            i, j = 0, c

            while i < rows and j < cols:
                ans.append(encodedText[i * cols + j])
                i += 1
                j += 1
            
        return "".join(ans).rstrip()
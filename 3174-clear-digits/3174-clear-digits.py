class Solution:
    def clearDigits(self, s: str) -> str:
        # This variable keeps track of the actual length of the resulting string
        ans_len, s = 0, list(s)

        # Iterate through each character in the input string
        for chr_idx in range(len(s)):
            # If the current character is a digit
            if s[chr_idx].isdigit():
                # Decrement ans_len to remove the last character from the result
                ans_len = max(ans_len - 1, 0)
            else:
                # Place the character in the "answer" portion of the string
                s[ans_len] = s[chr_idx]
                ans_len += 1
        
        # Resize the string to match the actual length of the answer
        s = s[:ans_len]

        return "".join(s)
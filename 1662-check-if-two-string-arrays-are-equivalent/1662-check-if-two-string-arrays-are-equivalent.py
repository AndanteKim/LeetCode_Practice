class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        # Pointers to mark the current word in the given two lists
        w1_ptr, w2_ptr = 0, 0
        # Pointers to mark the character in the string pointed by the above pointers
        str1_ptr, str2_ptr = 0, 0
        
        # While we still have the string in any of the two given lists
        while w1_ptr < len(word1) and w2_ptr < len(word2):
            # If the characters at the two string are same, increment the string pointers
            # Otherwise return false
            if word1[w1_ptr][str1_ptr] != word2[w2_ptr][str2_ptr]:
                return False
            str1_ptr += 1
            str2_ptr += 1
            
            # If the string pointer reaches the end of string in the list word1
            # Move to the next string in the list and reset the string pointer to 0
            if str1_ptr == len(word1[w1_ptr]):
                w1_ptr += 1
                str1_ptr = 0
            
            # If the string pointer reaches the end of string in the list word2,
            # Move to the next string in the list and reset the string pointer to 0
            if str2_ptr == len(word2[w2_ptr]):
                w2_ptr += 1
                str2_ptr = 0
            
        return w1_ptr == len(word1) and w2_ptr == len(word2)
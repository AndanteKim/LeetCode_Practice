class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        def store_abbreviations(curr_word: str, index: int, abbreviated_count: int) -> None:
            if index == len(word):
                # If the length of the last abbreviated substring is 0, add an empty string.
                if abbreviated_count > 0:
                    curr_word += str(abbreviated_count)
                abbreviations.append(curr_word)
                return
            
            # Option 1: Keep the current character
            store_abbreviations(curr_word + (str(abbreviated_count) if abbreviated_count > 0 else "") + word[index], index + 1, 0)
            
            # Option 2: Abbreviate the current character.
            store_abbreviations(curr_word, index + 1, abbreviated_count + 1)
            
        
        
        abbreviations, n = [], len(word)
        store_abbreviations("", 0, 0)
        
        return abbreviations
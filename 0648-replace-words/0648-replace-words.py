class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        def shortest_root(word: str, dict_set: Set[str]) -> str:
            # Find the shortest root of the word in the dictionary
            for i in range(len(word)):
                root = word[0:i]
                if root in dict_set:
                    return root
            
            # There is not a corresponding root in the dictionary
            return word
        
        words, dict_set = sentence.split(), set(dictionary)
        # Replace each word in sentence with the corresponding shortest root
        for word in range(len(words)):
            words[word] = shortest_root(words[word], dict_set)
        
        return " ".join(words)
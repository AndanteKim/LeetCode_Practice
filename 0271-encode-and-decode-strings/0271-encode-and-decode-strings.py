class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encoded_string = ""
        for s in strs:
            encoded_string += str(len(s)) + '/:' + s
        return encoded_string

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        decoded_strings = []
        i = 0
        
        while i < len(s):
            delim = s.find('/:', i)
            length = int(s[i:delim])
            str_ = s[delim + 2 : delim + 2 + length]
            decoded_strings.append(str_)
            i = delim + 2 + length
        return decoded_strings


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
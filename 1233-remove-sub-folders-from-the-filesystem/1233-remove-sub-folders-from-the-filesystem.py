class Solution:
    class TrieNode:
        def __init__(self):
            self.is_end_of_folder = False
            self.children = dict()
 
    def __init__(self):
        self.root = self.TrieNode()
    
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # Build Trie from folder paths
        for path in folder:
            curr_node = self.root
            names = path.split("/")
            
            for name in names:
                if name == "":
                    continue
                
                # Create new node if it doesn't exist
                if name not in curr_node.children:
                    curr_node.children[name] = self.TrieNode()
                curr_node = curr_node.children[name]
                
            # Mark the end of the folder path
            curr_node.is_end_of_folder = True
            
        # Check each path for subfolders
        ans = []
        
        for path in folder:
            curr_node = self.root
            names = path.split("/")
            is_subfolder = False
            
            for i, name in enumerate(names):
                if name == "":
                    continue
                next_node = curr_node.children[name]
                
                # Check if the current folder path is a subfolder of an existing folder
                if next_node.is_end_of_folder and i != len(names) - 1:
                    is_subfolder = True
                    break   # Found a subfolder
                curr_node = next_node
                
            # If not a subfolder, add to the result
            if not is_subfolder:
                ans.append(path)
                
        return ans
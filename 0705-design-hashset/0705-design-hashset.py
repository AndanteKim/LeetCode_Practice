class MyHashSet:

    def __init__(self):
        self.keyRange = 769
        self.bucketArray = [Bucket() for i in range(self.keyRange)]
        
    def _hash(self, key: int) -> int:
        return key % self.keyRange

    def add(self, key: int) -> None:
        bucketIndex = self._hash(key)
        self.bucketArray[bucketIndex].insert(key)
        
    def remove(self, key: int) -> None:
        bucketIndex = self._hash(key)
        self.bucketArray[bucketIndex].delete(key)

    def contains(self, key: int) -> bool:
        bucketIndex = self._hash(key)
        return self.bucketArray[bucketIndex].exists(key)
    
class Bucket:
    def __init__(self):
        self.tree = BSTree()
    
    def insert(self, value: int) -> None:
        self.tree.root = self.tree.insertIntoBST(self.tree.root, value)
    
    def delete(self, value: int) -> None:
        self.tree.root = self.tree.deleteNode(self.tree.root, value)
    
    def exists(self, value: int) -> bool:
        return self.tree.searchBST(self.tree.root, value) is not None
    
class TreeNode:
    def __init__(self, value: int):
        self.val = value
        self.left = None
        self.right = None
        
class BSTree:
    def __init__(self):
        self.root = None
    
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root or val == root.val:
            return root
        
        return self.searchBST(root.left, val) if val < root.val else self.searchBST(root.right, val)
    
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        
        if val > root.val:
            root.right = self.insertIntoBST(root.right, val)
        elif val == root.val:
            return root
        else:
            root.left = self.insertIntoBST(root.left, val)
        return root

    def successor(self, root: Optional[TreeNode]) -> int:
        root = root.right
        while root.left:
            root = root.left
        return root.val
    
    def predecessor(self, root: Optional[TreeNode]) -> int:
        root = root.left
        while root.right:
            root = root.right
        return root.val
    
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        else:
            if not (root.left or root.right):
                root = None
            elif root.right:
                root.val = self.successor(root)
                root.right = self.deleteNode(root.right, root.val)
            else:
                root.val = self.predecessor(root)
                root.left = self.deleteNode(root.left, root.val)
        
        return root

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
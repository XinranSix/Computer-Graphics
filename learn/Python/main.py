class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def buildTree(preorder: list[int], inorder: list[int]) -> TreeNode:
    if not preorder:
        return None
    root = TreeNode(preorder[0])
    stack = [root]
    inorderIndex = 0
    for i in range(1, len(preorder)):
        preorderVal = preorder[i]
        node = stack[-1]
        if node.val != inorder[inorderIndex]:
            node.left = TreeNode(preorderVal)
            stack.append(node.left)
        else:
            while stack and stack[-1].val == inorder[inorderIndex]:
                node = stack.pop()
                inorderIndex += 1
            node.right = TreeNode(preorderVal)
            stack.append(node.right)
    return root


def dfs(root: TreeNode):
    if not root:
        return []
    return [root.val] + dfs(root.left) + dfs(root.right)


def bfs(root: TreeNode) -> list[list[int]]:
    if not root:
        return []
    res = []
    queue = [root]
    while queue:
        size = len(queue)
        tmp = []
        for _ in range(size):
            r = queue.pop(0)
            tmp.append(r.val)
            if r.left:
                queue.append(r.left)
            if r.right:
                queue.append(r.right)
        res.append(tmp)
    return res


preorder = [1, 2, 3, 4, 5, 6, 7, 8]
inorder = [3, 2, 4, 5, 1, 7, 6, 8]

bt = buildTree(preorder, inorder)

res = dfs(bt)
print(res)
res = bfs(bt)
print(res)
print("tes")

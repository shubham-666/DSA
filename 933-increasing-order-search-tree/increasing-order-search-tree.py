class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        nodes = []

        def inorder(node):
            if not node:
                return

            inorder(node.left)
            nodes.append(node)
            inorder(node.right)

        inorder(root)

        for i in range(len(nodes) - 1):
            nodes[i].left = None
            nodes[i].right = nodes[i + 1]

        nodes[-1].left = None
        nodes[-1].right = None

        return nodes[0]
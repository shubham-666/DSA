class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        queue = deque([root])

        while queue:
            size = len(queue)
            found_x = False
            found_y = False

            for _ in range(size):
                node = queue.popleft()

                # x and y are siblings
                if node.left and node.right:
                    if {node.left.val, node.right.val} == {x, y}:
                        return False

                if node.val == x:
                    found_x = True

                if node.val == y:
                    found_y = True

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            # Both found at the same level
            if found_x and found_y:
                return True

            # Only one found at this level
            if found_x or found_y:
                return False

        return False
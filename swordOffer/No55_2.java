class JudgeBalanceTree {
    class Depth {
        int d = 0;
    }
    public boolean IsBalanced_Solution(TreeNode root) {
        Depth depth = new Depth();
        return isBalanced(root, depth);
    }

    private boolean isBalanced(TreeNode root, Depth depth) {
        if (root == null) {
            depth.d = 0;
            return true;
        }
        Depth left = new Depth();
        Depth right = new Depth();
        if (isBalanced(root.left, left) && isBalanced(root.right, right)) {
            if (Math.abs(left.d - right.d) <= 1) {
                depth.d = 1 + Math.max(left.d, right.d);
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
    }
}

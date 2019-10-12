class KthNodeSolution {
    private TreeNode res;
    int count = 0;
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        KthNodeCore(pRoot, k);
        return res;
    }

    private void KthNodeCore(TreeNode pRoot, int k)
    {
        if (pRoot == null)  return;
        KthNodeCore(pRoot.left, k);
        count++;
        if (count == k)     res = pRoot;
        KthNodeCore(pRoot.right, k);
    }
}
class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}

 class TreeAndList {
    private TreeNode lastNode = null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        if (pRootOfTree == null)    return null;
        TreeNode listHead = pRootOfTree;

        convertCore(pRootOfTree);
        while (listHead.left != null) {
            listHead = listHead.left;
        }
        return listHead;
    }

    private void convertCore(TreeNode pRootOfTree) {
        if (pRootOfTree == null)    return;
        convertCore(pRootOfTree.left);
        pRootOfTree.left = lastNode;
        if (lastNode != null)   lastNode.right = pRootOfTree;
        lastNode = pRootOfTree;
        convertCore(pRootOfTree.right);
    }
}
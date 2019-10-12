class SerializeTree {
    int index = -1;
    // 先序遍历
    String Serialize(TreeNode root) {
        if (root == null) {
            return "#!";
        }
        String st = root.val + "!";
        st += Serialize(root.left);
        st += Serialize(root.right);
        return st;
    }

    TreeNode Deserialize(String str) {
        String[] stt = str.split("!");
        TreeNode node = null;
        index++;

        if (!stt[index].equals("#")) {
            node = new TreeNode(Integer.parseInt(stt[index]));
            node.left = Deserialize(str);
            node.right = Deserialize(str);
        }

        return node;
    }
}
import java.util.ArrayList;
import java.util.LinkedList;

class PrintTreeInZhi {
     class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;
        }
    }

    public ArrayList<ArrayList<Integer>> Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> > res = new ArrayList<>();
        if (pRoot == null)  return res;

        int curCount = 1;
        boolean goRight = true;
        LinkedList<TreeNode> list = new LinkedList<>();
        list.add(pRoot);
        while (list.size() > 0) {
            int count = 0;
            ArrayList<Integer> tl = new ArrayList<>();
            for (int i = 0; i < curCount; i++) {
                TreeNode t = list.remove();
                if (goRight) {
                    tl.add(t.val);
                } else {
                    tl.add(0, t.val);
                }
                if (t.left != null) {
                    list.add(t.left);
                    count++;
                }
                if (t.right !=null) {
                    list.add(t.right);
                    count++;
                }
            }
            goRight = !goRight;
            curCount = count;
            res.add(tl);
        }
        return res;
    }
}

import java.util.ArrayList;
import java.util.LinkedList;

class PrintTreeUpToDown {
    ArrayList<ArrayList<Integer>> Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> > res = new ArrayList<>();
        if (pRoot == null)  return res;

        LinkedList<TreeNode> list = new LinkedList<>();
        list.add(pRoot);
        int curCount = 1;
        while (list.size() > 0) {
            int count = 0;
            ArrayList<Integer> al = new ArrayList<>();
            for (int i = 0; i < curCount; i++) {
                TreeNode t = list.remove();
                al.add(t.val);
                if (t.left != null) {
                    list.add(t.left);
                    count++;
                }
                if (t.right != null) {
                    list.add(t.right);
                    count++;
                }
            }
            curCount = count;
            res.add(al);
        }
        return res;
    }
}
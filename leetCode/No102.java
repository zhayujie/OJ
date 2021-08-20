import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * @author yujiezha
 * @description
 * @date 2021/8/19
 */
public class No102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < levelSize; i++) {
                TreeNode t = queue.poll();
                if (t.left != null) {
                    queue.add(t.left);
                }
                if (t.right != null) {
                    queue.add(t.right);
                }
                list.add(t.val);
            }
            res.add(list);
        }
        return res;
    }
}

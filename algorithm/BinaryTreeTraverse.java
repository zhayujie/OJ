import java.util.LinkedList;

public class BinaryTreeTraverse {
    public void preOrderTraverse(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            resolve(node);
            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }
        }
    }

    public void inOrderTraverse(TreeNode root) {
        if (root == null)   return;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        while (!stack.isEmpty() || node != null) {
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else {
                TreeNode temp = stack.pop();
                resolve(temp);
                node = temp.right;
            }
        }
    }

    public void postOrderTraverse(TreeNode root) {

    }

    private void resolve(TreeNode node) {
        System.out.println(node.val);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(6);
        root.left = new TreeNode(5);
        root.left.left = new TreeNode(3);
        root.right = new TreeNode(9);
        root.right.left = new TreeNode(8);

        new BinaryTreeTraverse().inOrderTraverse(root);
    }
}


class Stack<T> {
    private LinkedList<T> list = new LinkedList<>();

    public void push(T t) {
        list.addLast(t);
    }

    public T pop() {
        return list.removeLast();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }
}

// 参考资料：https://cloud.tencent.com/developer/article/1392637

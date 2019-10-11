import java.util.Queue;

class FindNextNode {
    public class TreeLinkNode {
        int val;
        TreeLinkNode left = null;
        TreeLinkNode right = null;
        TreeLinkNode next = null;

        TreeLinkNode(int val) {
            this.val = val;
        }
    }

    public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        if (pNode == null) return null;
        if (pNode.right != null) {
            TreeLinkNode temp = pNode.right;
            while (temp.left != null) {
                temp = temp.left;
            }
            return temp;
        }
        while (pNode.next != null) {
            if (pNode.next.left == pNode) {
                return pNode.next;
            }
            pNode = pNode.next;
        }
      
        return null;
    }
}
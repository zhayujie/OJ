import java.util.*;

/**
 * @author zhayujie
 * @description 重排链表
 * @date 2020/10/20
 */
class Solution143 {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        List<ListNode> nodes = new ArrayList<>();
        ListNode cur = head;
        // 1.遍历链表，放入list中
        while (cur != null) {
            nodes.add(cur);
            cur = cur.next;
        }
        int i = 0;
        int j = nodes.size() - 1;
        // 2.双指针指向首尾依次链接
        while (i < j) {
            nodes.get(i).next = nodes.get(j);
            i++;
            nodes.get(j).next = nodes.get(i);
            j--;
        }
        nodes.get(i).next = null;

        // 其他方法: 1.找链表中点(快慢指针) 2.右边链表反转 3.左右交叉合并
    }

    public static void main(String[] args) {
        ListNode node = new ListNode(1);
        node.next = new ListNode(2);
        node.next.next = new ListNode(3);
        node.next.next.next = new ListNode(4);
        new Solution143().reorderList(node);
        ListNode cur = node;
        while (cur != null) {
            System.out.println(cur.val);
            cur = cur.next;
        }
    }
}
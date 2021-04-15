import common.ListNode;

/**
 * @author yujiezha
 * @description 括号生成
 * @date 2020/12/16
 */
public class No025 {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode pre = dummy;
        ListNode end = dummy;
        while (true) {
            for (int i = 0; i < k && end != null; i++) {
                end = end.next;
            }
            if (end == null) {
                // 不足k个，退出
                break;
            }
            ListNode start = pre.next;
            ListNode next = end.next;
            // 暂时截断
            end.next = null;
            // 翻转该段链表
            reverse(start);
            // 前一段指向新的头部
            pre.next = end;
            pre = start;
            // 这一段的末尾指向下一段的头部
            start.next = next;
            // end移动到这一段的末尾
            end = pre;
        }
        return dummy.next;
    }

    public void reverse(ListNode head) {
        ListNode pre = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
    }

    public static void main(String []args) {
    }
}
/**
 * @author zhayujie
 * @description 反转链表
 * @date 2021/8/3
 */
public class No206 {

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode root = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return root;
    }

    // 迭代法
//    public ListNode reverseList(ListNode head) {
//        ListNode prev = null;
//        ListNode next;
//        while (head != null) {
//            next = head.next;
//            head.next = prev;
//            prev = head;
//            head = next;
//        }
//        return prev;
//    }
}

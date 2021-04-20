import java.util.PriorityQueue;

/**
 * @author yujiezha
 * @description 两两交换链表中的节点
 * @date 2020/12/16
 */
public class No024 {
    public ListNode swapPairs(ListNode head) {
        ListNode res = head;
        ListNode prev = null;
        ListNode next;
        while (head != null) {
            next = head.next;
            if (next == null) {
                // 下一个节点为空时，直接返回
                return res;
            }
            // 中 -> 下.下
            head.next = next.next;
            // 下.下 -> 中
            next.next = head;
            if (prev != null) {
                // 上 -> 下
                prev.next = next;
            } else {
                // 如果是前两个节点，头直接指向下
                res = next;
            }
            //更新上一个节点
            prev = head;
            // 下一次交换
            head = head.next;
            /**
             * 用递归写
             * ListNode next = head.next;
             * head.next = swapPairs(next.next);
             * next.next = head;
             * return next;
             */
        }
        return res;
    }

    public static void main(String args[]) {
    }
}

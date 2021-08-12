import common.ListNode;

/**
 * @author yujiezha
 * @description 括号生成
 * @date 2020/12/16
 */
public class No025_00 {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummyHead = new ListNode();
        dummyHead.next = head;
        ListNode prevTail = dummyHead;
        int count = 0;
        while (head != null) {
            count++;
            if (count %k == 0) {
                // 临时截断 [curHead ... head]
                ListNode nextHead = head.next;
                ListNode curHead = prevTail.next;
                head.next = null;
                // 翻转这一组 [head ... curHead], 并和前后的组相连
                prevTail.next = reverseList(curHead);
                curHead.next = nextHead;
                // 继续下一组
                head = nextHead;
                prevTail = curHead;
                continue;
            }
            head = head.next;
        }
        return dummyHead.next;
    }

    private ListNode reverseList(ListNode head) {
        ListNode next, prev = null;
        while (head != null) {
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    public static void main(String []args) {

    }
}
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class DeleteDupNode {
    static class ListNode {
        int val;
        ListNode next = null;
        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode deleteDuplication(ListNode pHead)
    {
//        if (pHead == null || pHead.next == null)  return pHead;
        ListNode tHead = new ListNode(-1);
        tHead.next = pHead;
        ListNode fast = pHead, slow = tHead;
        while (fast != null) {
            if (fast.next != null && fast.next.val == fast.val) {
                while (fast.next != null && fast.next.val == fast.val) {
                    fast = fast.next;
                }
                fast = fast.next;
                slow.next = fast;
            } else {
                slow = slow.next;
                fast = fast.next;
            }
        }
        LinkedList<Integer> l = new LinkedList<>();

        return tHead.next;
    }
}

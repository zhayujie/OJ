class NodeLoopEntry {
    static class ListNode {
        int val;
        ListNode next = null;
        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode EntryNodeOfLoop(ListNode pHead)
    {
        if (pHead == null)  return null;
        // 1.判断是否有环
        ListNode fast = pHead.next, slow = pHead;
        while (fast != slow) {
            if (slow == null || fast == null || fast.next == null)  return null;
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2.计算环的长度
        int count = 1;
        fast = fast.next;
        while (fast != slow) {
            fast = fast.next;
            count++;
        }

        // 3.计算环的入口
        fast = pHead;
        slow = pHead;
        for (int i = 0; i < count; i++) {
            fast = fast.next;
        }
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }

    public static void main(String[] args) {
        ListNode head = new NodeLoopEntry.ListNode(1);
        head.next = new NodeLoopEntry.ListNode(2);
        head.next.next = head;
        System.out.println(new NodeLoopEntry().EntryNodeOfLoop(head).val);
    }
}

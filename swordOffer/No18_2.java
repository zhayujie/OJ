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
        if (pHead == null)  return null;
        int cur = pHead.val;
        ListNode fast = pHead, slow = pHead;
        while (true) {
            int count = 0;
            while (fast != null && fast.val == cur) {
                fast = fast.next;
                count++;
            }
            if (count > 1) {
                if (pHead.val == cur) {
                    pHead = fast;
                }
                slow.next = fast;
                slow = fast;
                if (fast == null) return pHead;
                cur = fast.val;
            }
        }
    }
}

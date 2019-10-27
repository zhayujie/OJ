class Solution02 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        int pro = 0;
        ListNode head = null, tmp = null;

        while(l1 != null || l2 != null || pro != 0) {
            int a = 0, b = 0;
            if (l1 != null) {
                a = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                b = l2.val;
                l2 = l2.next;
            }
            int v = (a + b + pro) % 10;
            pro = (a + b + pro) / 10;

            if (head == null) {
                head = new ListNode(v);
                tmp = head;
            } else {
                tmp.next = new ListNode(v);
                tmp = tmp.next;
            }
        }
        return head;
    }
}
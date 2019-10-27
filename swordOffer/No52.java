class CommonNode {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        if (pHead1 == null || pHead2 == null)   return null;
        int len1 = 0, len2 = 0;
        ListNode p1 = pHead1, p2 = pHead2;
        // 计算长度
        while (p1 != null || p2 != null) {
            if (p1 != null) {
                len1++;
                p1 = p1.next;
            }
            if (p2 != null) {
                len2++;
                p2 = p2.next;
            }
        }
        // 长的先走
        if (len1 >= len2) {
            p1 = pHead1;
            p2 = pHead2;
        } else {
            p1 = pHead2;
            p2 = pHead1;
        }
        for (int i = 0; i < Math.abs(len2 - len1); i++) {
            p1 = p1.next;
        }

        // 寻找公共节点
        while (p1 != null) {
            if (p1 == p2)   return p1;
            p1 = p1.next;
            p2 = p2.next;
        }

        return null;
    }
}
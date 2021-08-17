/**
 * @author yujiezha
 * @description 双指针解法
 * @date 2020/12/16
 */
public class No160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        int countA = 0, countB = 0;
        ListNode ha = headA, hb = headB;
        while (ha.next != null) {
            countA++;
            ha = ha.next;
        }
        while (hb.next != null) {
            countB++;
            hb = hb.next;
        }
        if (ha != hb) {
            return null;
        }
        ListNode big, small;
        if (countA > countB) {
            big = headA;
            small = headB;
        } else {
            big = headB;
            small = headA;
        }
        int diff = Math.abs(countA - countB);
        for (int i = 0; i < diff; i++) {
            big = big.next;
        }
        while (small != null) {
            if (big == small) {
                return big;
            }
            big = big.next;
            small = small.next;
        }
        return null;
    }

    public static void main(String[] args) {

    }
}

import java.util.ArrayList;
import java.util.List;

/**
 * @author yujiezha
 * @description 合并两个有序链表
 * @date 2020/12/16
 */
public class No021 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next =  mergeTwoLists(l1, l2.next);
            return l2;
        }
    }

    public static void main(String args[]) {
    }
}

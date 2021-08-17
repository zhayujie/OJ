import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author yujiezha
 * @description 双指针解法
 * @date 2020/12/16
 */
public class No141 {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while (true) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) {
                return true;
            }
        }

    }

    public static void main(String[] args) {

    }
}

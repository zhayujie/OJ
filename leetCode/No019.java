import java.util.ArrayList;
import java.util.List;

/**
 * @author yujiezha
 * @description 删除倒数第N个节点
 * @date 2020/12/16
 */
public class No019 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return null;
        }
        List<ListNode> list = new ArrayList<>();
        while (head != null) {
            list.add(head);
            head = head.next;
        }
        if (n > list.size()) {
            return list.get(0);
        }
        if (n == list.size()) {
            return list.get(0).next;
        }
        int k = list.size() - n;
        list.get(k - 1).next = list.get(k).next;
        return list.get(0);
    }

    public static void main(String args[]) {
    }
}

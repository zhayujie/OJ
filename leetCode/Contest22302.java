import java.util.ArrayList;
import java.util.List;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22302 {
    public ListNode swapNodes(ListNode head, int k) {
        List<ListNode> nodes = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            nodes.add(cur);
            cur = cur.next;
        }
        if (nodes.size() <= 1 || (nodes.size()%2==1 && k == nodes.size()/2+1)) {
            return head;
        }
        int start = k-1;
        int end = nodes.size() - k;
        if (start > end) {
            int temp = end;
            end = start;
            start = temp;
        }
        nodes.get(start).next = nodes.get(end).next;
        if (end > start + 1) {
            nodes.get(end).next = nodes.get(start + 1);
            nodes.get(end - 1).next = nodes.get(start);
        } else {
            nodes.get(end).next = nodes.get(start);
        }
        if (start > 0) {
            nodes.get(start-1).next = nodes.get(end);
        } else {
            return nodes.get(end);
        }
        return head;
    }

    public static void main(String[] args) {

    }

    private class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}

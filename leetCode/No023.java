import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

/**
 * @author yujiezha
 * @description 合并K个升序链表
 * @date 2020/12/16
 */
public class No023 {
    public ListNode mergeKLists(ListNode[] lists) {
        // 其实也可以把整个node丢到优先队列中
        PriorityQueue<int[]> queue = new PriorityQueue<>((t1, t2) -> t1[1] < t2[1] ? -1 : 1);
        for (int i = 0; i < lists.length; i++) {
            ListNode head = lists[i];
            if (head == null) {
                continue;
            }
            // 0:当前链表索引, 1:当前节点的值
            int[] item = new int[]{i, head.val};
            queue.add(item);
        }
        return mergeKLists(queue, lists);
    }

    private ListNode mergeKLists(PriorityQueue<int[]> queue, ListNode[] lists) {
        if (queue.isEmpty()) {
            return null;
        }
        int[] item = queue.poll();
        int index = item[0];
        ListNode node = lists[index];
        lists[index] = node.next;
        if (node.next != null) {
            int[] elem = new int[]{index, node.next.val};
            queue.add(elem);
        }
        node.next = mergeKLists(queue, lists);
        return node;
    }

    public static void main(String args[]) {
    }
}

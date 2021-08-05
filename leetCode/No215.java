import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author yujiezha
 * @description
 * @date 2021/8/4
 */
public class No215 {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(k, (t1, t2) -> t1 < t2 ? -1 : 1);
        for (int i = 0; i < k; i++) {
            pq.offer(nums[i]);
        }

        for (int i = k; i < nums.length; i++) {
            int num = nums[i];
            Integer top = pq.peek();
            if (num > top) {
                pq.remove();
                pq.offer(num);
            }
        }
        return pq.peek();
    }
}

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22003 {
    public int maxResult(int[] nums, int k) {
        // dp[i]表示最后一步位置为i时，能获得的最大得分
        // dp[i] = max(dp[i-k]...dp[i-1]) + nums[i]
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        // 双端链表，存储的值是在dp[]中的索引
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 1; i < dp.length; i++) {
            // nums[i-1]入队前吧比它小的都移除，因为即使这些数在滑动窗口内，也永远不会被使用到
            // 这样，队列中更小的数同时一定在更后面
            while (!deque.isEmpty() && dp[deque.peekLast()] <= dp[i-1]) {
                deque.pollLast();
            }
            deque.offerLast(i-1);
            // 如果最大值已经过期，则直接移除
            if (deque.peekFirst() < i - k) {
                deque.pollFirst();
            }
            dp[i] = dp[deque.peekFirst()] + nums[i];
        }
        return dp[nums.length-1];
    }
}

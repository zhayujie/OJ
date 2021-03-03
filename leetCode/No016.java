import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author yujiezha
 * @description 双指针解法
 * @date 2020/12/16
 */
public class No016 {
    public int threeSumClosest(int[] nums, int target) {
        int minSum = nums[0] + nums[1] + nums[2];
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                int expectSum = target - nums[i];
                int sum = nums[j] + nums[k];
                if (sum == expectSum) {
                    return target;
                } else if (sum < expectSum) {
                    j++;
                } else {
                    k--;
                }
                minSum = Math.abs(sum - expectSum) < Math.abs(minSum - target) ? sum + nums[i] : minSum;
            }
        }
        return minSum;
    }

    public static void main(String args[]) {
        int[] nums = new int[]{-1,2,1,-4};
        System.out.println(new No016().threeSumClosest(nums,1));
    }
}

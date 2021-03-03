import java.util.*;

/**
 * @author yujiezha
 * @description 双指针解法
 * @date 2020/12/16
 */
public class No015 {
    public List<List<Integer>> threeSum(int[] nums) {
        int target = 0;
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            // 对i去重
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                int sum = target - nums[i];
                if (nums[j] + nums[k] == sum) {
                    List<Integer> numRes = new ArrayList<>();
                    numRes.add(nums[i]);
                    numRes.add(nums[j++]);
                    numRes.add(nums[k--]);
                    res.add(numRes);
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                } else if (nums[j] + nums[k] < sum) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }

    public static void main(String args[]) {
        int[] nums = new int[]{-1,0,1,2,-1,-4};
        System.out.println(new No015().threeSum(nums));
    }
}

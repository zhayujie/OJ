import java.util.*;

/**
 * @author yujiezha
 * @description 双指针解法
 * @date 2020/12/16
 */
public class No018 {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int t = 0; t < nums.length; t++) {
            if (t > 0 && nums[t] == nums[t-1]) {
                continue;
            }
            for (int i = t+1; i < nums.length; i++) {
                if (i > t+1 && nums[i] == nums[i-1]) {
                    continue;
                }
                int j = i + 1;
                int k = nums.length - 1;
                while (j < k) {
                    int expectSum = target - nums[t] - nums[i];
                    int sum = nums[j] + nums[k];
                    if (expectSum == sum) {
                        List<Integer> list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[k]);
                        list.add(nums[t]);
                        res.add(list);
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j-1]) {
                            j++;
                        }
                        while (j < k && nums[k] == nums[k+1]) {
                            k--;
                        }

                    } else if (sum < expectSum) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return res;
    }

    public static void main(String args[]) {
        int[] nums = new int[]{-2,-1,-1,1,1,2,2};
        System.out.println(new No018().fourSum(nums, 0));
    }
}

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author yujiezha
 * @description 双指针解法
 * @date 2020/12/16
 */
public class No015_00 {
    public List<List<Integer>> threeSum(int[] nums) {
        int target = 0;
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1, k = nums.length-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    List<Integer> r = new ArrayList<>();
                    r.add(nums[i]);
                    r.add(nums[j]);
                    r.add(nums[k]);
                    res.add(r);
                    while (j < k && nums[++j] == nums[j-1]) {
                    }
                    while (j < k && nums[--k] == nums[k+1]) {
                    }
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{-1,0,1,2,-1,-4};
        System.out.println(new No015_00().threeSum(nums));
    }
}

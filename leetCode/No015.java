import java.util.*;

/**
 * @author yujiezha
 * @description
 * @date 2020/12/16
 */
public class No015 {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        // 存储 val-index 的map
        Map<Integer, Integer> map = new HashMap<>();
        int start = 0, end = nums.length - 1;

        for (int i = start; i <= end; i++) {
            map.put(nums[i], i);
        }

        while (start < end) {
            Integer index = map.get(-(start + end));
            if (index == null) {

            }
        }

        return null;
    }
}

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22002 {
    public int maximumUniqueSubarray(int[] nums) {
        int max = 0, sum = 0, i, j;
        int[] sums = new int[nums.length];
        Map<Integer, Integer> map = new HashMap<>();

        // 计算前缀和
        for (int k = 0; k < nums.length; k++) {
            sum += nums[k];
            sums[k] = sum;
        }

        // 双指针
        for (i = 0, j = 0; j < nums.length; j++) {
            Integer index = map.get(nums[j]);
            if (index != null && index >= i) {
                max = Math.max(sum(i, j-1, sums), max);
                i = index + 1;
            }
            map.put(nums[j], j);
        }
        return Math.max(max, sum(i, nums.length-1, sums));
    }

    private int sum(int i, int j, int[] sums) {
        return i == 0 ? sums[j] : sums[j] - sums[i-1];
    }


    public static void main(String[] args) {
//        int[] nums = new int[]{187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
       int[] nums = new int[]{10000,1,10000,1,1,1,1,1,1};
        System.out.println(new Contest22002().maximumUniqueSubarray(nums));
    }
}

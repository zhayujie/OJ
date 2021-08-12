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
        Arrays.sort(nums);

        return res;
    }

    public static void main(String args[]) {
        int[] nums = new int[]{-1,0,1,2,-1,-4};
        System.out.println(new No015_00().threeSum(nums));
    }
}

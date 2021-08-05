/**
 * @author yujiezha
 * @description
 * @date 2021/8/5
 */
public class No215_02 {
    public int findKthLargest(int[] nums, int k) {
        return findKey(nums, 0, nums.length-1, k);
    }

    public int findKey(int[] nums, int lo, int hi, int k) {
        int p = partition(nums, lo, hi);
        if (p == k - 1) {
            return nums[p];
        } else if (p > k - 1) {
            return findKey(nums, lo, p-1, k);
        } else {
            return findKey(nums, p+1, hi, k);
        }
    }

    private int partition(int[] nums, int lo, int hi) {
        if (lo >= hi) {
            return hi;
        }
        int v = nums[lo];
        int i = lo, j = hi+1;

        while (true) {
            while (nums[++i] > v) {
                if (i == hi) {
                    break;
                }
            }
            while (nums[--j] < v) {
            }
            if (i >= j) {
                break;
            }
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1};
        System.out.println(new No215_02().findKthLargest(nums, 1));
    }
}

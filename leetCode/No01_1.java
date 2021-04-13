import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class No01_1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            List<Integer> indexList = map.get(nums[i]);
            if (indexList == null) {
                List<Integer> newIndexList = new ArrayList<>();
                newIndexList.add(i);
                map.put(nums[i], newIndexList);
            } else {
                indexList.add(i);
            }
        }
        for (Integer num : map.keySet()) {
            int another = target - num;
            List<Integer> anotherIndex = map.get(another);
            if (anotherIndex == null) {
                continue;
            }
            if (another == num) {
                if (anotherIndex.size() < 2) {
                    continue;
                }
                return new int[]{anotherIndex.get(0), anotherIndex.get(1)};
            } else {
                return new int[]{map.get(num).get(0), map.get(another).get(0)};
            }
        }

        return nums;
    }

    public static void main(String args[]) {
        int[] nums = {2, 2, 11, 15};
        No01_1 solution = new No01_1();
        int[] res = new No01_1().twoSum(nums, 4);
        System.out.println(res[0] + " " + res[1]);
    }
}
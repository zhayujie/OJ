import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            List<Integer> list = map.get(nums[i]);
            if (list == null) {
                list = new ArrayList<>();
                list.add(i);
                map.put(nums[i], list);
            } else {
                list.add(i);
                map.put(nums[i], list);
            }
        }
        int[] resArray = new int[2];
        for (Map.Entry<Integer, List<Integer>> entry: map.entrySet()) {
            int key = entry.getKey();
            List<Integer> list = map.get(target - key);
            if (list != null) {
//                System.out.println("key: " + key + " target: " + list.get(0));
                if (target == 2 * key) {
                    if (list.size() < 2)     continue;
                    resArray[0] = list.get(0);
                    resArray[1] = list.get(1);
                } else {
                    List<Integer> keyList = map.get(key);
                    resArray[0] = keyList.get(0);
                    resArray[1] = list.get(0);
                    break;
                }
            }
        }
        return resArray;
    }

    public static void main(String args[]) {
        int[] nums = {2, 2, 11, 15};
        Solution solution = new Solution();
        int[] res = solution.twoSum(nums, 4);
        System.out.println(res[0] + " " + res[1]);
    }
}
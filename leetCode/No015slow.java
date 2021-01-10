import java.util.*;

/**
 * @author yujiezha
 * @description
 * @date 2020/12/16
 */
public class No015slow {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, List<int[]>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j < nums.length; j++) {
                Integer plus = nums[i] + nums[j];
                int[] pair = new int[]{i, j};
                List<int[]> pairs = map.get(plus);
                if (pairs == null) {
                    pairs = new ArrayList<>();
                    pairs.add(pair);
                    map.put(plus, pairs);
                } else {
                    pairs.add(pair);
                }
            }
        }
        Map<String, Boolean> flagMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            List<int[]> pairs = map.get(nums[i] * -1);
            if (pairs == null) {
                continue;
            }
            for (int[] pair : pairs) {
                int index1 = pair[0];
                int index2 = pair[1];
                if (i == index1 || i == index2) {
                    continue;
                }
                List<Integer> comb = new ArrayList<>();
                comb.add(nums[i]);
                comb.add(nums[index1]);
                comb.add(nums[index2]);
                String key = getKey(comb);
                if (flagMap.get(key) == null) {
                    res.add(comb);
                    flagMap.put(key, true);
                }
            }
        }
        return res;
    }

    private String getKey(List<Integer> list) {
        List<Integer> newList = new ArrayList<>(list);
        newList.sort(Integer::compareTo);
        StringBuilder sb = new StringBuilder();
        for (Integer elem : newList) {
            sb.append(elem.toString()).append("_");
        }
        return sb.toString();
    }
}

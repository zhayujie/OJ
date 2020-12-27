import java.util.*;

/**
 * @author yujiezha
 * @description
 * @date 2020/12/16
 */
public class No015fast {
    public List<List<Integer>> threeSum(int[] nums) {

//        long t1 = System.currentTimeMillis();
        List<Integer> newNums = new ArrayList<>();
        Arrays.sort(nums);
        if (nums.length > 0) {
            newNums.add(nums[0]);
        }
        int eqCount = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                eqCount++;
            } else {
                eqCount = 1;
            }
            if (eqCount <= 3) {
                newNums.add(nums[i]);
            }
        }
        System.out.println(newNums);

        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < newNums.size(); i++) {
            List<Integer> indexList = map.get(newNums.get(i));
            if (indexList == null) {
                List<Integer> index = new ArrayList<>();
                index.add(i);
                map.put(newNums.get(i), index);
            } else {
                if (indexList.size() < 3) {
                    indexList.add(i);
                }
            }
        }
//        long t2 = System.currentTimeMillis();
        Map<String, Boolean> flagMap = new HashMap<>();
//        System.out.println("t2 - t1: " + (t2-t1));
        int count = 0;
        for (int i = 0; i < newNums.size(); i++) {
            for (int j = i+1; j < newNums.size(); j++) {
                int num1 = newNums.get(i);
                int num2 = newNums.get(j);
                List<Integer> nums3 = map.get(-num1 - num2);
                if (nums3 == null) {
                    continue;
                }
                count++;
                for (Integer index3 : nums3) {
                    if (index3 == i || index3 == j) {
                        continue;
                    }
                    String key = getKey(num1, num2, newNums.get(index3));
                    if (flagMap.get(key) == null) {
                        List<Integer> comb = new ArrayList<>();
                        comb.add(num1);
                        comb.add(num2);
                        comb.add(newNums.get(index3));
                        res.add(comb);
                        flagMap.put(key, true);
                        // 找到一个可用的就直接退出，否则超时
                        break;
                    }
                }
            }
        }
//        long t3 = System.currentTimeMillis();
//        System.out.println("t2 - t1:" + (t2 - t1));
//        System.out.println("t3 - t2:" + (t3 - t2));
        System.out.println("次数: " + count);

        return res;
    }

    private String getKey(int num1, int num2, int num3) {
        int k1, k2, k3;
        k1 = Math.min(num1, num2);
        k2 = Math.max(num1, num2);
        if (num3 < k1) {
            k3 = k2;
            k2 = k1;
            k1 = num3;
        } else if (num3 < k2) {
            k3 = k2;
            k2= num3;
        } else {
            k3 = num3;
        }
        return k1 + "_" + k2 + "_" + k3;
    }


    public static void main(String[] args) {
    }
}

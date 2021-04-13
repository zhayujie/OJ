import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/**
 * @author zhayujie
 * @description O(N)
 * @date 2020/12/20
 */
public class Contest22202_1 {
    public int countPairs(int[] deliciousness) {
        int[] sums = new int[22];
        Map<Integer, Integer> map = new HashMap<>();
        int start = 1;
        for (int i = 0; i < 22; i++) {
            sums[i] = start;
            start *= 2;
        }
        for (int del : deliciousness) {
            Integer val = map.get(del);
            map.put(del, val == null ? 1 : val+1);
        }
        long count = 0;
        // 对去重后的map进行遍历, 第68个case没过
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int curCount = 0;
            int x = entry.getKey();
            for (int i = 0; i < 22; i++) {
                int y = sums[i] - x;
                Integer yVal = map.get(y);
                if (yVal == null) {
                    continue;
                }
                curCount += (y == x) ? yVal - 1 : yVal;
            }
            count += curCount * entry.getValue();
        }
        return (int) (count / 2 % 1000000007);
    }

    public static void main(String[] args) {
        File file = new File("/Users/zyj/Desktop/111");
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
            String s = br.readLine();
            String[] strs = s.split(",");
            int[] nums = new int[strs.length];
            for (int i = 0; i < strs.length; i++) {
                nums[i] = Integer.parseInt(strs[i]);
            }
            System.out.println(new Contest22202_1().countPairs(nums));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

import java.io.*;
import java.util.*;

/**
 * @author zhayujie
 * @description 通过65/72
 * @date 2020/12/20
 */
public class Contest22202_slow {
    public int countPairs(int[] deliciousness) {
        long t1 = System.currentTimeMillis();
        boolean[] map = new boolean[2097153];
        int[] countMap = new int[1048576];
        int start = 1;
        for (int i = 1; i <= 22; i++) {
            map[start] = true;
            start *= 2;
        }
        long count = 0;
        Set<Integer> set = new HashSet<>();
        for (int num : deliciousness) {
            boolean res = set.add(num);
            if (res) {
                countMap[num] = 1;
            } else {
                countMap[num] += 1;
            }
        }
        deliciousness = new int[set.size()];
        int k = 0;
        for (Integer num : set) {
            deliciousness[k++] = num;
        }

        for (int i = 0; i < deliciousness.length; i++) {
            int curCount = 0;
            for (int j = 0; j < deliciousness.length; j++) {
                if (map[deliciousness[i] + deliciousness[j]]) {
                    if (j == i) {
                        curCount += countMap[deliciousness[j]] -1;
                    } else {
                        curCount += countMap[deliciousness[j]];
                    }
                }
            }
            count += curCount * countMap[deliciousness[i]];
        }
        long t2 = System.currentTimeMillis();
        System.out.println(t2 - t1 + " ms");
        return (int) ((count / 2) % 100000007);
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
            System.out.println(new Contest22202_slow().countPairs(nums));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

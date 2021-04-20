import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author yujiezha
 * @description
 * @date 2021/4/13
 */
public class TpcTest1 {
    public static boolean isSelect(int num, Map<Integer, Boolean> map) {
        for (int i = 1; i < num; i++) {
            int j = num - i;
            if (j != i && map.get(i) == null && map.get(j) == null) {
                return true;
            }
        }
        return false;
    }

    public static int calNums(int[] arr) {
        int count = 0;
        Map<Integer, Boolean> map = new HashMap<>();
        for (int num : arr) {
            map.put(num, Boolean.TRUE);
        }
        for (int num : arr) {
            if (isSelect(num, map)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int groups = scan.nextInt();
        for (int i = 0; i < groups; i++) {
            int nums = scan.nextInt();
            int[] arr = new int[nums];
            for (int j = 0; j < nums; j++) {
                int num = scan.nextInt();
                arr[j] = num;
            }
            System.out.print(calNums(arr));
            if (i < groups - 1) {
                System.out.print("\n");
            }
        }
    }
}

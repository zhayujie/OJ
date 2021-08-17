import java.util.Arrays;
import java.util.Scanner;

/**
 * @author yujiezha
 * @description 可以若干次数交换 a[i] 和 a[(i+2) mod n]，判断是否能构造出有序数组
 * 思路：交换是可以连通传递的 (union):
 *       1.对于长度为奇数的数组，一定可以通过交换变成有序数列
 *       2.对于长度为偶数的数组，分成两个子序列，分别排序后判断是否能构成有序数列
 * @date 2021/4/13
 */
public class TpcTest3 {

    public static boolean calNums(int[] arr) {
        int len = arr.length;
        if (len % 2 == 1) {
            return true;
        }
        int[] arr1 = new int[len / 2];
        int[] arr2 = new int[len / 2];
        int t = 0, k = 0;
        for (int i = 0; i < arr.length; i++) {
            if (i % 2 == 0) {
                arr1[t++] = arr[i];
            } else {
                arr2[k++] = arr[i];
            }
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        for (int i = 0; i < arr1.length - 1; i++) {
            if (arr2[i] < arr1[i] || arr2[i] > arr1[i+1]) {
                return false;
            }
        }
        return arr2[arr2.length-1] >= arr1[arr1.length-1];
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
            if (calNums(arr)) {
                System.out.print("Yes");
            } else {
                System.out.print("No021_new");
            }
            if (i < groups - 1) {
                System.out.print("\n");
            }
        }
    }
}

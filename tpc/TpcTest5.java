import java.util.Arrays;
import java.util.Scanner;


public class TpcTest5 {

    public static boolean canWin(int[] arr1, int[] arr2, int rank) {
        int tScore = arr1[0] + arr2[0];
        int count = 1;
        for (int i = 1; i < arr1.length; i++) {
            int p1 = arr1[i];
            int p2 =arr2[i];
            if (p1 > tScore) {
                count++;
            } else {
                continue;
            }
        }
        return rank >= count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int groups = scan.nextInt();
        for (int i = 0; i < groups; i++) {
            int nums = scan.nextInt();
            int rank = scan.nextInt();
            int[] arr1 = new int[nums];
            int[] arr2 = new int[nums];

            for (int j = 0; j < nums; j++) {
                int num = scan.nextInt();
                arr1[j] = num;
            }
            for (int j = 0; j < nums; j++) {
                int num = scan.nextInt();
                arr2[j] = num;
            }
            if (canWin(arr1, arr2, rank)) {
                System.out.print("Yes");
            } else {
                System.out.print("No");
            }
//            if (i < groups - 1) {
                System.out.print("\n");
//            }
        }
    }
}

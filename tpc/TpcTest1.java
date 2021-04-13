import java.util.List;
import java.util.Scanner;

/**
 * @author yujiezha
 * @description
 * @date 2021/4/13
 */
public class TpcTest1 {
    public static boolean perfectSequence(int[] arr) {
        int numZero = 0;
        int numPos = 0;
        int numNag = 0;
        for (int num : arr) {
            if (num == 0) {
                numZero++;
            } else if (num < 0) {
                numNag++;
            } else {
                numPos++;
            }
        }
        if (numNag < numPos) {
            return numNag + numZero >= numPos - 1;
        } else if (numPos  < numNag) {
            return numPos + numZero >= numNag - 1;
        } else {
            return true;
        }
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
            if (perfectSequence(arr)) {
                System.out.print("Yes");
            } else {
                System.out.print("No");
            }
            if (i < groups - 1) {
                System.out.print("\n");
            }
        }
    }
}

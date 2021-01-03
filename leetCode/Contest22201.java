import java.util.*;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22201 {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> {
            return a[1] < b[1] ? 1 : -1;
        });
        int count = 0;
        for (int[] box : boxTypes) {
            int num = Math.min(truckSize, box[0]);
            count += num * box[1];
            truckSize -= num;
            if (truckSize == 0) {
                break;
            }
        }
        return count;
    }
    public static void main(String[] args) {
    }
}

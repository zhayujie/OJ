import java.util.ArrayList;

class TwoSum {
    public ArrayList<Integer> FindNumbersWithSum(int [] array, int sum) {
        ArrayList<Integer> res = new ArrayList<>();
        int lo = 0, hi = array.length-1;
        while (lo < hi) {
            int curSum = array[lo] + array[hi];
            if (curSum == sum) {
                // x * y 的乘积 一定小于  (x+a) * (y-a)
                res.add(0, Math.min(array[lo], array[hi]));
                res.add(1, Math.max(array[lo], array[hi]));
                break;
            } else if (curSum < sum) {
                lo++;
            } else {
                hi--;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] array = {1};
        System.out.println(new TwoSum().FindNumbersWithSum(array, 1).toString());
    }
}

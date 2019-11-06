public class BinarySearch {
    public int search(int[] a, int target) {
        int lo = 0, hi = a.length - 1;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] < target) {
                lo = mid + 1;
            } else if (a[mid] > target) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        return lo;
    }

    public static void main(String[] args) {
        int[] a = {1, 3, 5, 7, 9};
        int res = new BinarySearch().search(a, 3);
        System.out.println(res);
    }
}

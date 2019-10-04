class NumberOfK {
    public int GetNumberOfK(int [] array , int k) {
        int first = getFirstK(array, k);
        int last = getLastK(array, k, 0, array.length-1);
        if (first == -1)    return 0;
        else                return last - first + 1;
    }

    private int getFirstK(int[] array, int k) {
        int lo = 0, hi = array.length - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (array[mid] < k)             lo = mid + 1;
            else if (array[mid] > k)        hi = mid - 1;
            else {
                if (mid == 0 || array[mid-1] != k)      return mid;
                else                        hi = mid - 1;
            }
        }
        return -1;
    }

    private int getLastK(int[] array, int k, int lo, int hi) {
        if (lo > hi)    return -1;
        int mid = lo + (hi - lo) / 2;

        if (array[mid] < k)             lo = mid + 1;
        else if (array[mid] > k)        hi = mid - 1;
        else {
            if (mid == array.length-1 || array[mid+1] != k)    return mid;
            else                        lo = mid + 1;
        }
        return getLastK(array, k, lo, hi);
    }

    public static void main(String[] args) {
        int[] nums = {1,1,1,1,1,1,1};
        System.out.println(new NumberOfK().GetNumberOfK(nums, 3));
    }
}

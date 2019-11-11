class MergeSortSolution {
    public int InversePairs(int [] array) {
        if (array.length == 0)  return 0;
        int[] aux = new int[array.length];
        return sort(array, aux, 0, array.length-1);
    }

    private int sort(int[] array, int[] aux, int lo, int hi) {
        if (lo >= hi)   return 0;
        int mid = (lo + hi) >> 1;
        int left =  sort(array, aux, lo, mid ) % 1000000007;
        int right = sort(array, aux, mid+1, hi) % 1000000007;
        int count = merge(array, aux, lo, mid, hi);
        return (left + count + right) % 1000000007;
    }

    private int merge(int[] array, int[] aux, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;
        int count = 0;

        for (int k = lo; k <= hi; k++) {
            aux[k] = array[k];
        }
        for (int k = lo; k <= hi; k++) {
            if (i > mid)                array[k] = aux[j++];
            else if (j > hi)            array[k] = aux[i++];
            else if (aux[j] < aux[i]) {
                array[k] = aux[j++];
                count += mid - i + 1;
                if (count >= 1000000007)    count %= 1000000007;
            } else {
                array[k] = aux[i++];
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5,6,7,0};
        System.out.println(new MergeSortSolution().InversePairs(nums));
    }

}
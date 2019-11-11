public class MergeSort {
    public void sort(int[] a) {
        int len = a.length;
        int[] aux = new int[len];
        sort(a, aux, 0, len-1);
    }

    private void sort(int[] a, int[] aux, int lo, int hi) {
        if (lo >= hi)   return;
        int mid = (lo + hi) >> 1;
        sort(a, aux, lo, mid);
        sort(a, aux, mid+1, hi);
        merge(a, aux, lo, mid, hi);
    }

    private void merge(int[] a, int[] aux, int lo, int mid, int hi) {
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {        // 复制到辅助数组
            aux[k] = a[k];
        }
        for (int k = lo; k <= hi; k++) {        // 归并回原数组
            if (i > mid)                    a[k] = aux[j++];
            else if (j > hi)                a[k] = aux[i++];
            else if (aux[i] <= aux[j])      a[k] = aux[i++];
            else                            a[k] = aux[j++];
        }
    }


    public static void main(String[] args) {
        int[] a = {5, 8, 9, 2, 3, 1, 6, 11};
        new HeapSort().sort(a);

        for (int elem : a) {
            System.out.print(elem + " ");
        }
    }
}

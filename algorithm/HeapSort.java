public class HeapSort {
    public void sort(int[] a) {
        int len = a.length;
        // 构造堆有序，从倒数第二行开始向上
        for (int k = len/2-1; k >= 0; k--) {
            sink(a, k, len-1);
        }
        // 堆排序，每次用堆顶（最大）和最后一个数交换，并对堆顶进行下沉
        while (len > 1) {
            swap(a, 0, len-1);
            len--;
            sink(a, 0, len-1);
        }
    }

    private void sink(int[] a, int k, int hi) {
        while (2 * k + 1 <= hi) {
            int j = 2 * k + 1;
            if (j < hi && a[j] < a[j+1])  j++;     // 选出两个子节点中更大的那个
            if (a[k] >= a[j])    break;            // 退出循环
            swap(a, k, j);
            k = j;
        }
    }

    private void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {
        int[] a = {5, 8, 9, 2, 3, 1, 6, 11};
        new HeapSort().sort(a);

        for (int elem : a) {
            System.out.print(elem + " ");
        }
    }
}

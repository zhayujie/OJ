public class QuickSort {
    public void sort(int[] a) {
        sort(a, 0, a.length - 1);
    }

    private void sort(int[] a, int lo, int hi) {
        if (lo >= hi)   return;             // 1.注意判断越界
        int p = partition(a, lo, hi);

        sort(a, lo, p-1);
        sort(a, p+1, hi);
    }

    private int partition(int[] nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo, j = hi+1;

        while (true) {
            while (nums[++i] < v) {
                if (i == hi) {
                    break;
                }
            }
            while (nums[--j] > v) {
            }
            if (i >= j) {
                break;
            }
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }


    private int partitionError(int[] a, int lo, int hi) {
        int v = a[lo];
        int i = lo + 1, j = hi;

        while (i <= j) {                    // 2.注意是 <= 不是 < 否则对{1,2}的数组无效，写成while(true)也行
            while (a[i] < v) {              // 3.不能写成 a[i--]
                i++;
                if (i >= hi)     break;     // 4.越界退出
            }
            while (a[j] > v) {
                j--;
            }
            if (i >= j) {                    // 5.注意 i>=j 要退出，否则死循环
                break;
            }
            swap(a, i, j);
        }
        swap(a, lo, j);

        return j;                           // 6.返回的切分点是j
    }

    private void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {
        int a[] = {5,2,3,1};
        new QuickSort().sort(a);

        for (int v: a) {
            System.out.println(v);
        }
    }
}

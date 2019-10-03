import java.util.HashMap;

class MoreThanHalf {
    public int MoreThanHalfNum_Solution(int [] array) {
        int len = array.length;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int ar: array) {
            Integer count = map.get(ar);
            if (count == null)   count = 0;
            map.put(ar, count+1);
            if (count+1 > len / 2) {
                return ar;
            }
        }
        return 0;
    }

    // 寻找中位数
    public int MoreThanHalfNum_fast(int [] array) {
        int len = array.length;
        if (len <= 0)   return 0;
        int mid = len / 2;
        int start = 0, end = len - 1;
        int index = partition(array, 0, len-1);

        while (index != mid) {
            if (index > mid)    end = index - 1;
            else                start = index + 1;
            index = partition(array, start, end);
        }
        int count = 0;
        for (int ar : array) {
            if (ar == array[index]) {
                count++;
            }
        }
        if (count > mid)    return array[index];
        else                return 0;
    }

    private int partition(int [] array, int lo, int hi) {
        // 注意 不加这句，当数组只有一个数时，++i会越界
        if (lo >= hi)   return hi;

        int i = lo, j = hi+1;
        int v = array[lo];

        while (true) {
            System.out.println("i: " + i + " j: " + j);
            // 注意要先++，否则元素相同时会不移动
            while (array[++i] < v) {
                if (i > hi)    break;
            }
            while (array[--j] > v) {
            }
            // 判断退出，此时不应该再交换
            if (i >= j)     break;
            swap(array, i, j);
        }
        swap(array, lo, j);
        return j;
    }
    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {
        int[] a = {1};

        MoreThanHalf moreThanHalf = new MoreThanHalf();
        int res = moreThanHalf.MoreThanHalfNum_fast(a);
        System.out.println(res);
    }
}
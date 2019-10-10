import sun.jvm.hotspot.jdi.IntegerTypeImpl;

class AppearOnce {
    public static final int[] a = new int[]{1,2};
    public void FindNumsAppearOnce(int [] array, int num1[] , int num2[]) {
        int num = 0;

        // 1.对整个数组异或
        for (int ar : array) {
            num ^= ar;
        }

        // 找到第一个1
        int first1 = getFirst1(num);

        // 2.将数组根据该位是不是1分成两部分，两个只出现1次的数一定也被分开
        int n1 = 0, n2 = 0;
        for (int ar : array) {
            // 3.分别异或，结果就是这两个数
            if (isBit1(ar, first1)) {
                n1 ^= ar;
            } else {
                n2 ^= ar;
            }
        }
        num1[0] = n1;
        num2[0] = n2;
    }

    private int getFirst1(int num) {
        for (int i = 0; num > 0; i++) {
            if ((num & 1) == 1) {
                return i;
            }
            num = num >> 1;
        }
        return 0;
    }

    private boolean isBit1(int num, int index) {
        return (num & (1 << index)) > 0;           // 注意这里不是 == 1
    }

    public static void main(String args[]) {
        int[] array = {2,2,1,3};
        int[] nums1 = {0};
        int[] nums2 = {1};
        new AppearOnce().FindNumsAppearOnce(array, nums1, nums2);
        System.out.println(nums1[0] + " " + nums2[0]);
        AppearOnce ap = new AppearOnce();
    }
}

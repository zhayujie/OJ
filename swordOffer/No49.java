import jdk.nashorn.internal.ir.debug.ObjectSizeCalculator;

import java.util.ArrayList;
import java.util.Arrays;

class UglyNumber {


    public int GetUglyNumber_Fast(int index) {
        // {1, 2, 3, 4, 5, 6}
        if (index <= 6) {
            return index;
        }
        ArrayList<Integer> list= new ArrayList<>();
        list.add(1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < index; i++) {
            int val = Math.min(2*list.get(i2), Math.min(3*list.get(i3), 5*list.get(i5)));
            list.add(val);
            if (2*list.get(i2) == val)         i2++;
            if (3*list.get(i3) == val)         i3++;        // 注意这里不能用else，否则会把重复的算进去
            if (5*list.get(i5) == val)         i5++;

        }
        return list.get(index-1);
    }

    public int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0;
        ArrayList<Long> list= new ArrayList<Long>(Arrays.asList(1L, 2L, 3L, 4L, 5L));

        if (index <= 5) {
            return list.get(index-1).intValue();
        }
        boolean success = false;
        int count = 5;
        for (int i = 2; ; i++) {
            for (int j = 1; j <= i; j++) {
                long val = list.get(i) * list.get(j);
                if (!list.contains(val)) {
                    list.add(val);
                    if (++count == 2 * index) {
                        success = true;
                        break;
                    }
                }
             }
             if (success)   break;
        }
        list.sort(null);
//        System.out.println(list.toString());

        return list.get(index-1).intValue();
    }

    public static void main(String[] args) {
//        System.out.println(new UglyNumber().GetUglyNumber_Fast(1500));
        int[][] a = new int[10][100];
        int[][] b = new int[100][10];


        System.out.println(ObjectSizeCalculator.getObjectSize(a));
        System.out.println(ObjectSizeCalculator.getObjectSize(b));

        int[] c = new int[0];
        System.out.println(ObjectSizeCalculator.getObjectSize(c));

    }
}


import java.util.ArrayList;
import java.util.LinkedList;

class LastRemaining {
    public int LastRemaining_Solution(int n, int m) {
        if (n < 1)  return -1;
        int curIndex = 0, curSize = n;
        ArrayList<Integer> list = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        while (curSize > 1) {
            curIndex = (curIndex + m-1) % curSize;
            list.remove(curIndex);
            curSize--;
            curIndex %= curSize;
        }
        return list.get(0);
    }

    public static void main(String[] args) {
        int n = new LastRemaining().LastRemaining_Solution(5, 3);
        System.out.println(n);
    }
}

import java.util.ArrayList;
import java.util.LinkedList;

class MaxInWindowsSolution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        int len = num.length;
        ArrayList<Integer> res = new ArrayList<>();
        if (len <= 0 || size == 0 || size > len)       return res;

        LinkedList<Integer> queue = new LinkedList<>();

        for (int i = 0; i < size; i++) {
            while (queue.size() != 0 && queue.peekLast() < num[i]) {
                queue.removeLast();
            }
            queue.add(num[i]);
        }

        for (int i = 0; i <= len-size; i++) {
            int newEle = num[i+size-1];
            while (queue.size() != 0 && queue.peekLast() < newEle) {
                queue.removeLast();
            }
            if (i != 0) {
                queue.add(newEle);
            }

            int front = queue.peekFirst();
            res.add(front);

            if (front == num[i]) {
                queue.removeFirst();
            }
        }
        return res;
    }
}

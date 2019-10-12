import java.util.Comparator;
import java.util.PriorityQueue;

class DataStreamMid {
    int count = 0;
    PriorityQueue<Integer> pqMax = new PriorityQueue<>();
    PriorityQueue<Integer> pqMin = new PriorityQueue<>(new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2.compareTo(o1);
        }
    });

    public void Insert(Integer num) {
        // 偶数放小顶堆
        if (count % 2 == 0) {
            pqMax.add(num);
            Integer max = pqMax.poll();
            pqMin.add(max);
        }
        // 奇数放大顶堆
        else {
            pqMin.add(num);
            Integer max = pqMin.poll();
            pqMax.add(max);
        }
        count++;
    }

    public Double GetMedian() {
        if (count % 2 == 0) {
            return Double.valueOf(String.valueOf((pqMin.peek() + pqMax.peek())*1.0 / 2));
        } else {
            return Double.valueOf(String.valueOf(pqMin.peek()));
        }
    }

    public static void main(String[] args) {
        DataStreamMid dm = new DataStreamMid();
        dm.Insert(5);
        dm.Insert(2);
        dm.Insert(3);
//        dm.Insert(4);
//        dm.Insert(1);
//        dm.Insert(6);
//        dm.Insert(7);
//        dm.Insert(0);
//        dm.Insert(8);
        System.out.println(dm.GetMedian());
    }
}

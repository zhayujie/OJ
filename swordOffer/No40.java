import java.util.*;

class LeastKNum {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        if (input.length < k || k == 0)   return new ArrayList<>();

        PriorityQueue<Integer> pq = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
        ArrayList<Integer> res = new ArrayList<>(k);

        int len = input.length;
        for (int i = 0; i < k && i < len; i++) {
            pq.offer(input[i]);
        }
        for (int i = k; i < len; i++) {
            Integer v = pq.peek();
            if (v == null)  break;
            if (input[i] < v) {
                pq.poll();
                pq.offer(input[i]);
            }
        }
        res.addAll(pq);

        return res;
    }



    public static void main(String[] args) {
        LeastKNum solution = new LeastKNum();
        int[] input = {4,5,1,6,2,7,3,8};

        System.out.println(solution.GetLeastNumbers_Solution(input, 0).toString());

    }
}



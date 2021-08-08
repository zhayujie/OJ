import java.util.PriorityQueue;

/**
 * @author zhayujie
 * @description
 * @date 2021/8/8
 */
public class Contest25302 {
    public int minStoneSum(int[] piles, int k) {
        int sum = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((i, j) -> i < j ? 1 : -1);
        for (int pile : piles) {
            pq.add(pile);
            sum += pile;
        }
        for (int i = 0; i < k; i++) {
            int max = pq.remove();
            int newEntry = max - (max / 2);
            pq.offer(newEntry);
            sum -= max / 2;
        }
        return sum;
    }

    public static void main(String[] args) {

    }
}

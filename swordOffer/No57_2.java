import java.awt.print.Pageable;
import java.util.ArrayList;

class ContinuousSequence {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer> > res = new ArrayList<>();
        if (sum < 3)    return res;
        int curSum = 3;
        int lo = 1, hi = 2;
        int mid = (sum+1) / 2;

        while (lo < hi && hi <= mid) {
            if (curSum < sum) {
                hi++;
                curSum += hi;
            } else if (curSum > sum) {
                curSum -= lo;
                lo++;
            } else {
                ArrayList<Integer> list = new ArrayList<>(hi-lo+1);
                for (int i = lo; i <= hi; i++) {
                    list.add(i);
                }
                res.add(list);
                hi++;
                curSum += hi;
            }
        }
        return res;
    }
}

import javax.smartcardio.Card;
import java.util.Arrays;

class CardContinuous {
    public boolean isContinuous(int [] numbers) {
        int len = numbers.length;
        if (len == 0)   return false;
        Arrays.sort(numbers);
        int count0 = 0, i = 0;
        while (i < len && numbers[i] == 0) {
            count0++;
            i++;
        }
        for (int j = i+1; j < len; j++) {
            int diff = numbers[j] - numbers[j-1];
            if (diff == 0)          return false;
            else if (diff > 1) {
                if (count0 < diff-1)    return false;
                count0 -= diff-1;
            }
        }
        return true;
    }
}

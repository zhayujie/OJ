import java.util.ArrayList;
import java.util.Arrays;

class ReverseString {
    public String ReverseSentence(String str) {
        String[] sts = str.split("\\s+");
        StringBuilder res = new StringBuilder();
        for (int i = sts.length - 1; i > 0; i--) {
            res.append(sts[i]);
            res.append(" ");
        }
        if (sts.length > 0) {
            res.append(sts[0]);
            return res.toString();
        } else {
            return str;
        }
    }
}

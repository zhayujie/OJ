import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22301 {
    public int[] decode(int[] encoded, int first) {
        int[] res = new int[encoded.length+1];
        res[0] = first;
        int cur = first;
        for (int i = 0; i < encoded.length; i++) {
            res[i+1] = cur ^ encoded[i];
            cur = res[i+1];
        }
        return res;
    }

    public static void main(String[] args) {
        int[] r= new Contest22301().decode(new int[]{6,2,7,3}, 4);
        for (int i : r) {
            System.out.println(i);
        }
    }
}

import java.util.ArrayList;
import java.util.List;

/**
 * @author yujiezha
 * @description 括号生成
 * @date 2020/12/16
 */
public class No022 {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        generateParenthesis(res, "", n, n);
        return res;
    }

    private void generateParenthesis(List<String> res, String str, int i, int j) {
        if (i == 0 && j == 0) {
            res.add(str);
            return;
        }
        if (i == 0) {
            generateParenthesis(res, str + ")", i, j - 1);
        } else if (i == j) {
            generateParenthesis(res, str + "(", i-1, j);
        } else {
            generateParenthesis(res, str + ")", i, j - 1);
            generateParenthesis(res, str + "(", i-1, j);
        }
    }

    public static void main(String args[]) {
        System.out.println(new No022().generateParenthesis(3));
    }
}

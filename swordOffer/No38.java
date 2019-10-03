import java.util.*;

class SortString {
    private HashSet<String> res = new HashSet<>();
    public ArrayList<String> Permutation(String str) {
        if (str.length() == 0)      return new ArrayList<>();
        ArrayList<Character> elem = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            elem.add(str.charAt(i));
        }
        boolean[] vis = new boolean[elem.size()];

        for (int i = 0; i < elem.size(); i++) {

            vis[i] = false;
        }
        generateStr("", elem, vis);
        ArrayList<String> list = new ArrayList<>(res);
        Collections.sort(list);
        return list;
    }

    private void generateStr(String str, ArrayList<Character> elem, boolean[] visited) {
        if (str.length() == elem.size()) {
            res.add(str);
            return;
        }
        for (int i = 0; i < elem.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                generateStr(str+ elem.get(i), elem, visited);
                visited[i] = false;
            }
        }
    }
}


class SimpleSortStr {
    private HashSet<String> res = new HashSet<>();

    public ArrayList<String> Permutation(String str) {
        if (str.length() == 0)      return new ArrayList<>();

        generateStr(new StringBuilder(str), 0);
        ArrayList<String> list = new ArrayList<>(res);
        Collections.sort(list);
        return list;
    }

    private void generateStr(StringBuilder src, int pos) {
        if (pos == src.length()) {
            res.add(src.toString());
            return;
        }
        for (int i = pos; i < src.length(); i++) {
            char temp = src.charAt(pos);
            src.setCharAt(pos, src.charAt(i));
            src.setCharAt(i, temp);

            generateStr(src, pos+1);

            temp = src.charAt(i);
            src.setCharAt(i, src.charAt(pos));
            src.setCharAt(pos, temp);
        }
    }
}

class runTest {
    public static void main(String args[]) {
        SimpleSortStr sst = new SimpleSortStr();
        ArrayList<String> ast = sst.Permutation("abc");
        System.out.println(ast.toString());
    }
}

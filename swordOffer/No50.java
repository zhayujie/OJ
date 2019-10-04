import java.util.HashMap;
import java.util.Map;

class NotRepeat {
    public int FirstNotRepeatingChar(String str) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            Integer index = map.get(str.charAt(i));
            if (index == null) {
                map.put(str.charAt(i), i);
            } else {
                map.put(str.charAt(i), -1);
            }
        }
        int min = str.length();
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() != -1) {
                min = Math.min(min, entry.getValue());
            }
        }

        return min == str.length() ? -1 : min;
    }
}

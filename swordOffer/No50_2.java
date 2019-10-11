class NotRepeatInStream {
    private int[] stream = new int[256];
    private int count = 0;
    public void Insert(char ch)
    {
        count++;
        if (stream[ch] == 0) {      // 之前未出现过
            stream[ch] = count;     // 记录出现的次序
        } else {
            stream[ch] = -1;        // 重复
        }
    }
    //return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int i = 0; i < 256; i++) {
            if (stream[i] != 0 && stream[i] != -1) {
                if (stream[i] < min) {
                    min = stream[i];
                    min_index = i;
                }
            }
        }
        return min_index == -1 ? '#' : (char) min_index;
    }
}

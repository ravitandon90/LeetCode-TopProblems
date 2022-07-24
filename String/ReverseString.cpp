// Problem: https://leetcode.com/problems/reverse-string/

class ReverseString {
    public void reverseString(char[] s) {
        int start = 0;
        int end = s.length - 1;
        while (start < end) {
            swap(s, start, end);
            ++start;
            --end;
        }
    }

    private void swap(char[] s, int x, int y) {
        char temp = s[x];
        s[x] = s[y];
        s[y] = temp;
    }
}
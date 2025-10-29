package arrays.string;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Strings {
    public static void main(String[] args) {
        // isPalindrome();
        // replaceAscii();
        // substrings();
    }

    public static boolean isPalindrome() {
        String str = "namjn";
        boolean palindrome = true;
        int left = 0;
        int right = str.length() - 1;

        while (left <= right) {
            if (str.charAt(left) != str.charAt(right)) {
                palindrome = false;
                break;
            }
            left++;
            right--;
        }
        return palindrome;
    }

    public static void replaceAscii() {
        String str = "cdEfG";
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < str.length(); i++) {
            if (i % 2 == 0) {
                sb.append((char) (str.charAt(i) + 1));
            } else {
                sb.append((char) (str.charAt(i) - 1));
            }
        }

        for (int i = 0; i < sb.length(); i++) {
            System.out.print(sb.charAt(i) + " ");
        }
    }

    public static void substrings() {
        String str = "code";
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j <= str.length(); j++) {
                System.out.print(str.substring(i, j) + " ");
            }
            System.out.println();
        }
    }

    public static int maxLengthBetweenEqualCharacters(String s) {
        // string s="abcba"
        // ans=3
        int[] res = new int[26];
        int maxlen = -1;
        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if (res[idx] > 0) {
                maxlen = Math.max(maxlen, i - res[idx]);
            } else {
                res[idx] = i + 1;
            }
        }
        return maxlen;
    }

    public static String reverseWords(String s) {
        // String str="the sky is blue"
        // String str=" hello world "
        s = s.trim();

        List<String> wordList = Arrays.asList(s.split("\\s+"));

        Collections.reverse(wordList);
        return String.join(" ", wordList);
    }

    public static boolean isPalindrome(String s) {
        // String s = "A man, a plan, a canal: Panama"
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }

            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            }
        }
        return true;
    }

    public static String largestOddNumber(String num) {
        // String s="34567";
        // res="34567"

        // String s="52";
        // res="5";
        int right = num.length() - 1;
        while (right >= 0) {
            if ((num.charAt(right) - '0') % 2 == 0) {
                right--;
            } else {
                break;
            }
        }
        return num.substring(0, right + 1);
    }
}

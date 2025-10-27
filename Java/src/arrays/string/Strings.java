package arrays.string;

public class Strings {
    public static void main(String[] args) {
        // isPalindrome();
        // replaceAscii();
        substrings();
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
}

package arrays.arraylist;

import java.util.ArrayList;

public class ArrayListProblems {
    public static void main(String[] args) {
        // Both arrays are sorted
        int[] arr1 = { 5, 7, 8 };
        int[] arr2 = { 4, 7, 8 };
        System.out.println(intersectionOfTwoArays(arr1, arr2));

        System.out.println(addTwoArrays(arr1, arr2));

        int[] arr = runningSum(arr2);
        for (int val : arr)
            System.out.print(val + " ");
    }

    public static ArrayList<Integer> intersectionOfTwoArays(int[] arr1, int[] arr2) {
        ArrayList<Integer> arraylist = new ArrayList<>();
        int m = arr1.length;
        int n = arr2.length;

        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (arr1[i] < arr2[j])
                i++;
            else if (arr1[i] > arr2[j])
                j++;
            else {
                arraylist.add(arr1[i]);
                i++;
                j++;
            }
        }
        return arraylist;
    }

    public static ArrayList<Integer> addTwoArrays(int[] arr1, int[] arr2) {
        ArrayList<Integer> arraylist = new ArrayList<>();

        int carry = 0;
        int m = arr1.length - 1;
        int n = arr2.length - 1;

        while (m >= 0 || n >= 0) {
            int sum = 0;
            if (m >= 0)
                sum += arr1[m];
            if (n >= 0)
                sum += arr2[n];

            sum += carry;
            int remainder = sum % 10;
            carry = sum / 10;
            arraylist.add(0, remainder);
            m--;
            n--;
        }
        if (carry != 0)
            arraylist.add(0, carry);

        return arraylist;
    }

    public static int[] runningSum(int[] arr) {
        int[] result = new int[arr.length];
        result[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            result[i] = result[i - 1] + arr[i];
        }
        return result;
    }
}

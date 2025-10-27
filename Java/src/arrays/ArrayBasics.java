package arrays;

public class ArrayBasics {
    public static void main(String[] args) {
        // Basics syntax of arrays
        // Initialization and declaration in one line
        int[] arr = new int[5];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;

        // Looping through an array
        // for (int i = 0; i < arr.length; i++) {
        // System.out.print(arr[i]);
        // }
        // System.out.println();

        // Enhanced for-loop
        for (int val : arr) {
            System.out.print(val + " ");
        }
        System.out.println();
        // swapArrayElements(arr, 0, arr.length - 1);
        // System.out.println();
        // for (int val : arr) {
        // System.out.print(val + " ");
        // }

        // System.out.println();
        // reverseAnArray(arr, 0, arr.length - 1);
        // for (int val : arr) {
        // System.out.print(val + " ");
        // }

        // System.out.println(maxArrayElement(arr));
        // System.out.println(minArrayElement(arr));

        rotateArrayKTimes(arr, 3);
        for (int val : arr) {
            System.out.print(val + " ");
        }
    }

    public static void swapArrayElements(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void reverseAnArray(int[] arr, int i, int j) {
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    public static int maxArrayElement(int[] arr) {
        int maxEl = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > maxEl)
                maxEl = arr[i];
        }
        return maxEl;
    }

    public static int minArrayElement(int[] arr) {
        int minEl = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < minEl)
                minEl = arr[i];
        }
        return minEl;
    }

    public static void rotateArrayKTimes(int[] arr, int k) {
        // k is the rotating factor
        k = k % arr.length;
        if (k < 0) {
            k += arr.length;
        }
        for (int r = 1; r <= k; r++) {
            int temp = arr[arr.length - 1];
            for (int i = arr.length - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
    }
}

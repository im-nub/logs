import java.util.Arrays;

public class heap_shell {

    // Heap Sort Implementation
    static void heapSort(int[] arr) {
        int n = arr.length;

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract elements
        for (int i = n - 1; i >= 0; i--) {
            // Swap root (max) with end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Call heapify on reduced heap
            heapify(arr, i, 0);
        }
    }

    static void heapify(int[] arr, int n, int i) {
        int largest = i; // root
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if left child is larger
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Check if right child is larger
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If root is not largest, swap and continue heapifying
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }

    // Shell Sort Implementation
    static void shellSort(int[] arr) {
        int n = arr.length;

        // Start with a large gap, then reduce
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Do gapped insertion sort
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;

                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                arr[j] = temp;
            }
        }
    }

    // Main Method
    public static void main(String[] args) {
        int[] data1 = {20, 35, 15, 7, 55, 1, -22};
        int[] data2 = Arrays.copyOf(data1, data1.length);

        System.out.println("Original Array:");
        System.out.println(Arrays.toString(data1));

        heapSort(data1);
        System.out.println("\nHeap Sorted:");
        System.out.println(Arrays.toString(data1));

        shellSort(data2);
        System.out.println("\nShell Sorted:");
        System.out.println(Arrays.toString(data2));
    }
}

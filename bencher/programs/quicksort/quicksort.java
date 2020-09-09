import java.util.Random;

public final class quicksort {
    public final static int BIG_NUMBER = 50_000_000;

    private final static void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    private final static int partition(int[] array, int begin, int end) {
        int smaller_end = begin-1;
        for(int larger_end = begin; larger_end < end; larger_end++){
            if(array[larger_end] <= array[end]){ // the last one is the pivot
                swap(array, ++smaller_end, larger_end);
            }
        }
        swap(array, ++smaller_end, end);
        return smaller_end;
    }

    public final static void quickSort(int[] array, int begin, int end) {
        if(begin < end){
            int split = partition(array, begin, end);
            quickSort(array, begin, split-1);
            quickSort(array, split+1, end);
        }
    }

    public static void main(String[] args) {
        // long startTime = System.currentTimeMillis();
        
        // // parse user input (problem size)
        // int size;
        // if(args.length <=0){
        //     size = BIG_NUMBER;
        // }
        // else {
        //     try {
        //         size = Integer.parseInt(args[0]);
        //     } catch (NumberFormatException e) {
        //         size = BIG_NUMBER;
        //     }
        // }

        // // generate an array of integer to sort
        // int[] intArray = new int[size];
        // Random rand = new Random();
        // for(int i=0; i<size; i++){
        //     intArray[i] = rand.nextInt(size);
        // }
        // long arrayGenDoneTime = System.currentTimeMillis();

        // // do quicksort
        // quickSort(intArray, 0, size-1);
        // long quicksortDoneTime = System.currentTimeMillis();

        // // print elapsed time
        // long randArrayGenTime = arrayGenDoneTime - startTime;
        // long sortingTime = quicksortDoneTime - arrayGenDoneTime;

        // System.out.println("Generate random array: " + randArrayGenTime + " ms");
        // System.out.println("Quicksorting: " + sortingTime + " ms");
    }
}
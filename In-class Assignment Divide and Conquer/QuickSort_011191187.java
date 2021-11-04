package Divideconquer;

public class QuickSort_011191187 {
    public static void main(String[] args) {
        QuickSort_011191187 q = new QuickSort_011191187();
        int[] arr = {10,15,5,19,16,188,99,14,27,35};
        q.qSort(arr,0,arr.length-1);
        for(int i = 0;i< arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }

    private void qSort(int[] arr, int low, int high) {
        if(low<high){
            qSort(arr,low,part(arr, low, high)-1);
            qSort(arr,part(arr, low, high)+1,high);
        }
    }

    private int part(int[] arr, int low, int high) {
        int pivot = arr[high],i = (low - 1);
        for(int j = low;j<high;j++){
            if(arr[j] <= pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return(i+1);
    }
}

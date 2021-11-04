package Divideconquer;

public class unique_final_011191187 {
    public static void main(String[] args) {
        int []arr = {1,2,2,2,2,30};
        if(BS(arr,0,arr.length+1)==-1){
            System.out.println("Not found any");
        }
        else{
            System.out.println(BS(arr,0,arr.length+1));
        }
    }
    public static int BS(int[] arr, int low, int high) {
        int mid = (low+high)/2;
        if(high<=low){
            return -1;
        }
        if(arr[mid] == arr[mid+1] || arr[mid] == arr[mid-1]){
            return arr[mid];
        }
        else{
            if(BS(arr,low,mid) != -1){
                return BS(arr,low,mid);
            }
            else if(BS(arr,mid+1,high) != -1){
                return BS(arr,mid+1,high);
            }
            return -1;
        }

    }
}

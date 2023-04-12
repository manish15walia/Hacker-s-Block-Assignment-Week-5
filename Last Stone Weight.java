import java.util.*;

public class Main{
    public static int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer>heap = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<stones.length;i++){
            heap.add(stones[i]);
        }
        while(heap.size()>1){
            int x = heap.poll();
            int y = heap.poll();

            if(x-y>0)
                heap.add(x-y);
            
        }
        if(heap.size()==1)
            return heap.poll();
        else
            return 0;
        
        
            }
            public static void main(String [] args){
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                
                int [] arr = new int[n];
                
                for(int i=0;i<n;i++){
                    arr[i]=sc.nextInt();
                }
                
               System.out.print(lastStoneWeight(arr));
            }
}

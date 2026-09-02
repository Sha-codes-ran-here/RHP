import java.util.*;
public package DAY_9;

class travelling {
    public static void main(String [] args){
        Scanner s= new Scanner(System.in);
        n=s.nextInt();
        Map<Integer,ArrayList<int[]>> g=new Hashmap<>();
        while(n--){
            int src=s.nextInt(),des=s.nextInt(),dis=s.nextInt();
            if(!g.containsKey(src)) g.put(src, new ArrayList<>());
            g.get(src).add(new int[] {des,dis});
            if(!g.containsKey(des)) g.put(des,new ArrayList<>());
            g.get(des).add(new int[] {src,dis});
        }
        int start=s.nextInt(),end=s.nextInt();
        PriorityQueue<int[]> upd=new PriorityQueue<>();
        upd.add(int[] {start,0});
        int shortest=0;
        while(!pq.isempty()){
            int [] list=pq.poll();
            int currcity=list[0],currdis=list[1];
            if(currcity == end){
                shortest=currdis;break;
            }
            if(visited.containsKey(currcity)) continue;
            v

        }

    }
    
}
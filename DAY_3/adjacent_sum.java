package RHP.DAY_3;
import java.util.*;
public class adjacent_sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R=sc.nextInt();
        int C=sc.nextInt();
        int grid[][] = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        int row=sc.nextInt();
        int col=sc.nextInt();
        int diff[][]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        long sum=0;
        for (int i = 0; i < 8; i++) {
            int newRow=row+diff[i][0];
            int newCol=col+diff[i][1];
            if(newRow>=0 && newRow<R && newCol>=0 && newCol<C){
                sum+=grid[newRow][newCol];
            }
        }
        System.out.println(sum);
    }
    
}

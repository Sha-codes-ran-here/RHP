import java.util.*;
public class Counting_rooms{
    public static void dfs(char[][] dp,int row,int col){
	dp[row][col]="#";
	if(dp[row-1][col]==".")
		dfs(dp,row-1,col);
	if(dp[row][col-1]==".")
		dfs(dp,row,col-1);
	if(dp[row+1][col]==".")
		dfs(dp,row+1,col);
	if(dp[row][col+1]==".")
		dfs(dp,row,col+1);
    }
    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        int R=s.nextInt();
        int C=s.nextInt();
        String[] IN=new String[R];
        char [][] dp=new char [R][C];
        for(int i=0;i<R;i++){
            IN[i]=s.nextLine();
		}
        for(int i=0;i<R;i++){
            int j=0;
            for(char c:IN[i].toCharArray()){
                dp[i][j]=c;
                j++;
            }
        }
	
	int rooms=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(dp[i][j]=="."){
				rooms++;
				dfs(dp,i,j);
			}
		}
	}
	System.out.println(rooms);
}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Main {
    private static final int MAX_TEMP = 200005;
    private static final int[] diff = new int[MAX_TEMP];
    private static final int[] admissible = new int[MAX_TEMP];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        int currentRecipes = 0;
        for (int i = 1; i < MAX_TEMP; i++) {
            currentRecipes += diff[i];
            admissible[i] = (currentRecipes >= k) ? 1 : 0;
        }
        for (int i = 1; i < MAX_TEMP; i++) {
            admissible[i] += admissible[i - 1];
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int ans = admissible[b] - admissible[a - 1];
            sb.append(ans).append("\n");
        }
        System.out.print(sb);
    }
}
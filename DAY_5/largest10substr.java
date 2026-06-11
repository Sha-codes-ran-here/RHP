import java.util.*;
public class LargestEqual01
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    String s = sc.nextLine();
		HashMap<Integer, Integer> map = new HashMap<>();

        int prefixSum = 0;
        int maxLength = 0;

        map.put(0, -1); // Handles substrings starting from index 0

        for (int i = 0; i < s.length(); i++) {

            if (s.charAt(i) == '1')
                prefixSum += 1;
            else
                prefixSum -= 1;

            if (map.containsKey(prefixSum)) {
                int length = i - map.get(prefixSum);
                maxLength = Math.max(maxLength, length);
            } else {
                map.put(prefixSum, i);
            }
        }
        System.out.println(maxLength);
	}
}
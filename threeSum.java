import java.util.*;
import java.io.*;

public class threeSum {
    public static List<List<Integer>> threeSum(int[] num) {
        Arrays.sort(num);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        for (int i = 0; i < num.length - 2; i++) {
        	if (i > 0 && num[i] == num[i - 1]) continue;
        	int j = i + 1, k = num.length - 1;
        	int a = num[i];
        	while (j < k) {
        		int b = num[j];
        		int c = num[k];
        		if (b + c + a <= 0) {
        			if (a + b + c == 0)
	        			res.add(Arrays.asList(a, b, c));
        			j++;
        			while (j < k && num[j] == num[j - 1]) j++;
        		} else {
        			k--;
        			while (k > j && num[k] == num[k + 1]) k--;
        		}
        	}
        }
        return res;
    }
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	PrintWriter out = new PrintWriter(System.out);
    	int n;
    	n = in.nextInt();
    	int[] num = new int[n];
    	for (int i = 0; i < n; i++) num[i] = in.nextInt();
    	threeSum A = new threeSum();
    	List<List<Integer>> res = new ArrayList<List<Integer>>();
    	res = A.threeSum(num);
    	for (int i = 0; i < res.size(); i++) out.println(res.get(i));
    	out.close();
    }
}

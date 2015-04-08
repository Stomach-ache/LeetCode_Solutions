import java.util.*;
import java.io.*;

public class threeSumClosest {
    public static int ThreeSumClosest(int[] num, int target) {
        Arrays.sort(num);
        //List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        int res = -1;
        boolean flag = false;
        for (int i = 0; i < num.length - 2; i++) {
        	if (i > 0 && num[i] == num[i - 1]) continue;
        	int j = i + 1, k = num.length - 1;
        	int a = num[i];
        	while (j < k) {
        		int b = num[j];
        		int c = num[k];
        		if (b + c + a <= target) {
        		    if (!flag) res = a + b + c;
        		    else if (Math.abs(a + b + c - target) < Math.abs(res - target)) res = a + b + c;
        		    flag = true;
        			j++;
        			while (j < k && num[j] == num[j - 1]) j++;
        		} else {
        			if (!flag) res = a + b + c;
        		    else if (Math.abs(a + b + c - target) < Math.abs(res - target)) res = a + b + c;
        		    flag = true;
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
    	int n, target;
    	n = in.nextInt();
    	target = in.nextInt();
    	int[] num = new int[n];
    	for (int i = 0; i < n; i++) num[i] = in.nextInt();
    	out.println(ThreeSumClosest(num, target));
    	out.close();
    }
}

import java.util.*;
import java.io.*;

public class MaximumGap {
    public static int maximumGap(int[] num) {
		int len = num.length;
		if (len < 2) return 0;
		int[] arr = new int[len];
		for (int i = 0; i < len; i++) arr[i] = num[i];
		RadixSort(arr);
		int res = 0;
		for (int i = 1; i < len; i++) res = Math.max(res, arr[i] - arr[i - 1]);
		return res;
    }
    public static void RadixSort(int[] num) {
   		ArrayList<ArrayList<Integer>> bucket = new ArrayList<ArrayList<Integer>>(10); 
   		for (int i = 0; i < 10; i++) bucket.add(new ArrayList<Integer>());
   		int len = num.length;
   		int[] ten = new int[10];
   		int a = 1;
   		for (int i = 0; i < 10; i++, a *= 10) ten[i] = a;
   		for (int i = 0; i < 10; i++) {
   			for (int j = 0; j < len; j++) {
   				int k = num[j] / ten[i] % 10;
   				bucket.get(k).add(num[j]);
   			}
   			int cc = 0;
   			for (int j = 0; j < 10; j++) if (bucket.get(j).size() > 0) {
   				for (int k = 0; k < bucket.get(j).size(); k++) num[cc++] = bucket.get(j).get(k);
   				bucket.get(j).clear();
   			}
   		}
    }
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	PrintWriter out = new PrintWriter(System.out);
    	int n;
    	n = in.nextInt();
    	int[] num = new int[n];
    	//List<Integer> num = new ArrayList<Integer>();
    	for (int i = 0; i < n; i++) {
    		num[i] = in.nextInt();
    	}
    	int res = maximumGap(num);
    	out.println(res);
    	for (int i = 0; i < n; i++) out.print(String.format("%d ", num[i]));
    	out.println();
    	out.close();
    }
}

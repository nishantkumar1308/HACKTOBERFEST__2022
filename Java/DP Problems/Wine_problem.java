// Program to calculate maximum price of wines


import java.io.*;

class wine {
	
	static int N = 1000;
	
	static int [][]dp = new int[N][N];
	static int [][]sell = new int[N][N];
	

	static int maxProfitUtil(int price[],
				int begin, int end, int n)
	{
		if (dp[begin][end] != -1)
			return dp[begin][end];
	
		int year = n - (end - begin);
	
		if (begin == end)
			return year * price[begin];
	
		int x = price[begin] * year +
				maxProfitUtil(price, begin + 1,
									end, n);
	

		int y = price[end] * year +
				maxProfitUtil(price, begin,
								end - 1, n);
	
		int ans = Math.max(x, y);
		dp[begin][end] = ans;
	
		if (x >= y)
			sell[begin][end] = 0;
		else
			sell[begin][end] = 1;
	
		return ans;
	}
	

	static int maxProfit(int price[], int n)
	{

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[i][j] = -1;
	
		int ans = maxProfitUtil(price, 0,
								n - 1, n);
	
		int i = 0, j = n - 1;
	
		while (i <= j) {
	
			if(sell[i][j] == 0){
				System.out.print( "beg ");
				i++;
			}
			else
			{
				System.out.print( "end ");
				j--;
			}
		}
	
		System.out.println();
	
		return ans;
	}
	
	public static void main (String[] args)
	{

		int price[] = { 2, 4, 6, 2, 5 };
	
		int n = price.length;
	
		int ans = maxProfit(price, n);
	
		System.out.println( ans );
	}
}


/* Program to find the probability of the Knight to remain inside the 
   chessboard after taking exactly K number of steps */


import java.io.*;

class probability {

	static final int N = 8;

	static int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    static int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };


	static boolean inside(int x, int y)
	{
		return (x >= 0 && x < N && y >= 0 && y < N);
	}

	static double findProb(int start_x, int start_y,
						int steps)
	{

		double dp1[][][] = new double[N][N][steps + 1];

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				dp1[i][j][0] = 1;

		for (int s = 1; s <= steps; ++s) {


			for (int x = 0; x < N; ++x) {

				for (int y = 0; y < N; ++y) {

					double prob = 0.0;


					for (int i = 0; i < 8; ++i) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (inside(nx, ny))
							prob
								+= dp1[nx][ny][s - 1] / 8.0;
					}

					dp1[x][y][s] = prob;
				}
			}
		}

		return dp1[start_x][start_y][steps];
	}

	public static void main(String[] args)
	{

		int K = 3;

		System.out.println(findProb(0, 0, K));
	}
}


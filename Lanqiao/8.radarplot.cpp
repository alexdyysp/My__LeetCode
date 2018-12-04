#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
//http://www.voidcn.com/article/p-onzjoqhi-bn.html
/*
作为H国的精英特工，你接到了一项任务，驾驶一辆吉普穿越布满监测雷达的禁区。
为了简化题目，我们可以把禁区想象为一个左下角是(0, 0)右上角是( W, H )的长方形区域。
区域中一共有 N 座雷达，其中第 i 座的坐标是(Xi,Yi )，监测范围是半径为 Ri 的圆形区域。
所有在圆内和圆上的运载工具都会被监测到。
你的目标是从左到右穿越禁区。
你可以选择线段(0, 0)-(0, H)上任意一点作为起点，线段(W, 0)-(W, H)上任意一点作为终点。
在禁区内你可以沿任意路线行驶，只要保持始终在禁区内并且没有被雷达监测到。
给出禁区内的雷达部署方案，你需要判断是否存在满足条件的行驶路线。
*/
int radar_plot[1024][1024];
int x[1024], y[1024], r[1024];

void build_graph(int N) {
	int nein[1024] = {0};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			long long dx = x[i] - x[j], dy = y[i] - y[j], sr = r[i] + r[j];
			if (dx * dx + dy * dy <= sr * sr) {
				radar_plot[i][nein[i]] = j;
				radar_plot[j][nein[j]] = i;
				nein[i]++;
				nein[j]++;
			}
		}
	}
	for (int i = 0; i < N; ++i)
		radar_plot[i][nein[i]] = -1;
}

int dfs(int i, int* done) {
	done[i] = 1;
	if (y[i] - r[i] <= 0)
		return 1;
	for (int k = 0; radar_plot[i][k] != -1; ++k) {
		int j = radar_plot[i][k];
		if (done[j] == 0)
			if (dfs(j, done))
				return 1;
	}
	return 0;
}

int main() {
	int T, W, H, N;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d%d%d", &W, &H, &N);
		for (int i = 0; i < N; ++i)
			scanf("%d%d%d", &(x[i]), &(y[i]), &(r[i]));
		build_graph(N);
		int done[1024] = {};
		int find = 0;
		for (int i = 0; i < N; ++i) {
			if (y[i] + r[i] >= H) {
				if (dfs(i, done)) {
					find = 1;
					printf("NO\n");
					break;
				}
			}
		}
		if (find == 0)
			printf("YES\n");
	}
}

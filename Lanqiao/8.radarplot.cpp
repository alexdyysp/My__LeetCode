#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
//http://www.voidcn.com/article/p-onzjoqhi-bn.html
/*
��ΪH���ľ�Ӣ�ع�����ӵ���һ�����񣬼�ʻһ�����մ�Խ��������״�Ľ�����
Ϊ�˼���Ŀ�����ǿ��԰ѽ�������Ϊһ�����½���(0, 0)���Ͻ���( W, H )�ĳ���������
������һ���� N ���״���е� i ����������(Xi,Yi )����ⷶΧ�ǰ뾶Ϊ Ri ��Բ������
������Բ�ں�Բ�ϵ����ع��߶��ᱻ��⵽��
���Ŀ���Ǵ����Ҵ�Խ������
�����ѡ���߶�(0, 0)-(0, H)������һ����Ϊ��㣬�߶�(W, 0)-(W, H)������һ����Ϊ�յ㡣
�ڽ����������������·����ʻ��ֻҪ����ʼ���ڽ����ڲ���û�б��״��⵽��
���������ڵ��״ﲿ�𷽰�������Ҫ�ж��Ƿ����������������ʻ·�ߡ�
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

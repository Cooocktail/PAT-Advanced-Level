#include <cstdio>

const int maxn = 10010;

int dp[maxn], pre[maxn], seq[maxn];

int main(int argc, char** argv) {
	int K;
	scanf("%d", &K);
	bool flag = false;
	for(int i = 0; i < K; i++){
		scanf("%d", &seq[i]);
		if(seq[i] >= 0) flag = true; //�ж��Ƿ�ȫΪ���� 
	}
	if(flag == false){ //ȫΪ�������0
		printf("0 %d %d", seq[0], seq[K - 1]); 
		return 0;
	}
	dp[0] = seq[0];
	pre[0] = 0; //pre���������洢��ǰ���к͵Ŀ�ʼλ�ã�Ҳ����i��λ�� 
	int indexI = 0, indexJ = 0, maxSum = dp[0];
	for(int i = 1; i < K; i++){
		if(dp[i - 1] >= 0){ //dp�洢�����Ե�ǰ�±�Ϊ���һλ������к� 
			dp[i] = dp[i - 1] + seq[i];
			pre[i] = pre[i - 1]; //�������к�ʱ����ʼλ�ò��� 
		}
		else{ //��dp[i - 1]С�ڵ���0�Ļ�����ô��ʱ�����к;�Ϊseq[i] 
			dp[i] = seq[i];
			pre[i] = i; 
		}
		if(dp[i] > maxSum){
			maxSum = dp[i];
			indexI = pre[i];
			indexJ = i;
		}
	}
	printf("%d %d %d", maxSum, seq[indexI], seq[indexJ]);
	
	return 0;
}

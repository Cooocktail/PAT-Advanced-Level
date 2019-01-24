#include <cstdio>

int main(int argc, char** argv) {
	int N;
	scanf("%d", &N);
	int* seq = new int[N];
	for(int i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}
	int sum = 0, pre = 0;
	for(int i = 0; i < N; i++) {
		if(seq[i] > pre) {
			sum += 6 * (seq[i] - pre) + 5;
		} else {
			sum += 4 * (pre - seq[i]) + 5;
		}
		pre = seq[i]; //���µ�ǰͣ���� 
	}
	printf("%d", sum);
	return 0;
}

#include <cstdio>
#include <string>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	if(sum < 0){ //������������ţ����ҽ���ת��Ϊ��������ȥ���Ÿ����㴦�� 
		printf("-");
		sum = -sum;
	}
	string result, tempStr = to_string(sum);
	int cnt = 0;
	for(int i = tempStr.length() - 1; i >= 0; i--, cnt++){
		if(cnt != 0 && cnt % 3 == 0){ //ÿ��3λ����һ��"," 
			result += ',';
		}
		result += tempStr[i];
	}
	for(int i = result.length() - 1; i >= 0; i--){
		printf("%c", result[i]);
	}
	return 0;
}

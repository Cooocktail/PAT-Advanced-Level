#include <string>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	if(sum < 0){ //负数则输出负号，并且将和转变为正数（除去符号更方便处理） 
		printf("-");
		sum = -sum;
	}
	string result, tempStr = to_string(sum);
	int cnt = 0;
	for(int i = tempStr.length() - 1; i >= 0; i--, cnt++){
		if(cnt != 0 && cnt % 3 == 0){ //每隔3位加上一个"," 
			result += ',';
		}
		result += tempStr[i];
	}
	for(int i = result.length() - 1; i >= 0; i--){
		printf("%c", result[i]);
	}
	return 0;
}

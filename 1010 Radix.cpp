#include <iostream> 
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

long long toDecimal(string N, int radix);
long long getLow(string N);

int main(int argc, char** argv) {
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	if(tag == 2) swap(N1, N2); //��tagΪ2ʱ������N1, N2,��������ݽ���ͳһ���� 
	long long decimalN1 = toDecimal(N1, radix);
	long long low = getLow(N2), high = max(low, decimalN1); //�ֱ�������Ҫ�ⶨ���Ƶ������ޣ���������ʱ������һ�������ޣ�ͬʱ��Ŀ˵���ˣ������Ʋ�Ψһʱ�������С�Ľ��ƣ����Ի�Ҫ����N1��ʮ��������Ϊ�ڶ��޶��������˴����ѵ㣬����ĥ��ĥ�� 
	while(low <= high){ //�������Ƚϴ󣬲��ö��ַ���ѹ��ʱ�� 
		long long mid = (low + high) / 2; //mid�����ԵĽ��� 
		long long decimalN2 = toDecimal(N2, mid);
		if(decimalN2 < 0 || decimalN2 > decimalN1){ //�ѵ㣺���radix̫�󳬳�long long�͵ķ�Χ����ʹdecimalN2��Ϊ��������ʱҲ�����˽��ƹ��� 
			high = mid - 1;
		}else if(decimalN2 < decimalN1){ //����ѡȡ��̫С 
			low = mid + 1;
		}else{ //�ҵ���ȷ�Ľ��ƣ������ 
			cout << mid;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}

long long toDecimal(string N, int radix){
	long long sum = 0;
	for(int i = 0; i < N.length(); i++){ //ע�����ֺ���ĸת����ʮ����ʱ��ʽ��һ�� 
		if(isdigit(N[i])) sum = sum * radix + N[i] - '0';
		else sum = sum * radix + N[i] - 'a' + 10;
	}
	return sum;
}

long long getLow(string N){ //��ý��Ƶ����� 
	char maxElement = '0';
	for(int i = 0; i < N.length(); i++){
		if(N[i] > maxElement) maxElement = N[i];
	}
	return (isdigit(maxElement) ? maxElement - '0' : maxElement - 'a' + 10) + 1; //��С����һ��������Ԫ�ش�1 
}

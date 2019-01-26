#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

const int maxn = 2010;
const int INF = 0x3f3f3f3f;
char subject[4] = {'A', 'C', 'M', 'E'};

typedef struct student{
	string id;
	int grade[4]; //grade���δ��A��C��M��E�ĳɼ� 
	int rank;
	student(){
		memset(grade, 0, sizeof(grade));
	}
}student;

typedef struct result{
	int rank;
	int sub; 
	result(){
		rank = INF;
		sub = -1;
	}
}result;

student stu[maxn];
map<string, result> mp; //�洢��õ������Ͷ�Ӧ�Ŀ�Ŀ 
int order; //��ʾ���ĸ��ɼ��������� 

bool cmp(student stu1, student stu2);

int main(int argc, char** argv) {
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		cin >> stu[i].id;
		for(int j = 1; j <= 3; j++){
			cin >> stu[i].grade[j];
			stu[i].grade[0] += stu[i].grade[j]; //ƽ����ֱ��ʹ�ú������棬������С������鷳 
		}
	}
	for(order = 0; order < 4; order++){ //order��ʾ�ֱ������ĸ��ɼ��������� 
		sort(stu, stu + N, cmp);
		for(int i = 0; i < N; i++){
			if(i == 0 || stu[i].grade[order] != stu[i - 1].grade[order]){
				stu[i].rank = i + 1;
			}else{
				stu[i].rank = stu[i - 1].rank;
			}
			if(stu[i].rank < mp[stu[i].id].rank){
				mp[stu[i].id].rank = stu[i].rank;
				mp[stu[i].id].sub = order;
			}
		}
	}
	for(int i = 0; i < M; i++){
		string query;
		cin >> query;
		if(mp[query].sub == -1){ //sub�ڹ��캯�����ֵ��-1����ʱ��ʾ����û��¼�룬��N/A 
			cout << "N/A" << endl;
		}else{
			cout << mp[query].rank << " " << subject[mp[query].sub] << endl;
		}
	}
	return 0;
}

bool cmp(student stu1, student stu2){
	return stu1.grade[order] > stu2.grade[order];
}

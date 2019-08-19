
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	//������ start�� 0�����ε� �������� �ε����� ù��°�� 1��°�̹Ƿ� 0��°�� ������ ���� 0�� �߰� �Ͽ����ϴ�. 
	array.insert(array.begin(), 0);
	//������ ���Ұ��� i
	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;
		for (int j = commands[i][0]; j <= commands[i][1]; j++) {// �� commands 0��° ���ں��� 1��°���ڱ��� array���� �߶�
			//[2,5,3]�̸� 2��°~5��°���� array���� �ڸ�����
			//������ ���� tmp�� �߰��մϴ�.
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end());//���� O(nlogn) #include <algorithm>
		answer.push_back(tmp[commands[i][2] - 1]);//������ ���� �ߴٽ��� ���ʹ� 0���� �����ϱ⶧����
		//�������� �ǹ��ϴ� 3��°�� ���Ϳ��� 2��°�� �ǹ��մϴ�.
	}
	return answer;
}

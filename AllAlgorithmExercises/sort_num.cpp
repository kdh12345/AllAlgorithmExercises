#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	//���ʹ� 0������ �����ϱ� ������ �� �տ� 0�� �߰��մϴ�.
	array.insert(array.begin(), 0);
	//Ŀ��� ������ ��ŭ ����(����)
	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;
		for (int j = commands[i][0]; j <= commands[i][1]; j++) {//Ŀ�ǵ� ù��° ������ ���� �ι�° ���������� �ڸ��ϴ�.
			//ex) [2,5,3]�̸� 2��° ���� 5��°���� array���Ҹ� �߶� tmp�ֽ��ϴ�.
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end());//����
		answer.push_back(tmp[commands[i][2] - 1]);//���Ϳ��� 3��°�� �ε���2�� �ǹ��մϴ�.
	}
	return answer;
}
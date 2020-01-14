#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	//벡터는 0번부터 시작하기 때문에 맨 앞에 0을 추가합니다.
	array.insert(array.begin(), 0);
	//커멘드 사이즈 만큼 돌고(가로)
	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;
		for (int j = commands[i][0]; j <= commands[i][1]; j++) {//커맨드 첫번째 적힌수 부터 두번째 적힌수까지 자릅니다.
			//ex) [2,5,3]이면 2번째 부터 5번째까지 array원소를 잘라서 tmp넣습니다.
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end());//정렬
		answer.push_back(tmp[commands[i][2] - 1]);//벡터에서 3번째는 인덱스2를 의미합니다.
	}
	return answer;
}
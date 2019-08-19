
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	//벡터의 start는 0부터인데 문제에서 인덱스의 첫번째는 1번째이므로 0번째에 임의의 숫자 0을 추가 하였습니다. 
	array.insert(array.begin(), 0);
	//각줄의 원소갯수 i
	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;
		for (int j = commands[i][0]; j <= commands[i][1]; j++) {// 각 commands 0번째 숫자부터 1번째숫자까지 array에서 잘라서
			//[2,5,3]이면 2번째~5번째까지 array에서 자르겠죠
			//임의의 벡터 tmp에 추가합니다.
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end());//정렬 O(nlogn) #include <algorithm>
		answer.push_back(tmp[commands[i][2] - 1]);//위에서 설명 했다시피 벡터는 0부터 시작하기때문에
		//문제에서 의미하는 3번째는 벡터에서 2번째를 의미합니다.
	}
	return answer;
}

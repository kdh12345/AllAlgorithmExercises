bool cmp(const string& a, const string& b) {
	if (a + b > b + a)
		return true;
	else
		return false;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str_arr;
	for (int i = 0; i < numbers.size(); i++)
		str_arr.push_back(to_string(numbers[i]));
	sort(str_arr.begin(), str_arr.end(), cmp);
	for (int i = 0; i < str_arr.size(); i++) {
		answer += str_arr[i];
	}
	if (answer[0] == '0')//예외처리
		return "0";
	return answer;
}
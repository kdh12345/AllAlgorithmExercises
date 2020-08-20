#include <iostream>
#include <vector>
using namespace std;
struct light{
	int D;
	int R;
	int G;
	int cycle;
};
bool greenLight(int idx, int Time,vector<light> v) {
	if (Time%v[idx].cycle > v[idx].R) {
		return true;
	}
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, l;
	cin >> n >> l;
	vector<light> v(n);
	for (int i = 0; i < n; i++) {
		int d, r, g;
		cin >> d >> r >> g;
		int cycle = r + g;
		v[i] = { d,r,g,cycle };
	}
	int ans = 0;
	int distance = 0;
	int i = 0;
	while (distance<l) {
		if (i < v.size()) {
			if (v[i].D == distance) {//��ȣ�� ��ġ�� ����.
				if (greenLight(i, ans, v)) {//�ʷϺ�
					ans++;
					distance++;
				}
				else {//�������̸� ��ٸ��� �ð� üũ
					int diff = ans % (v[i].cycle);
					ans += v[i].R - diff;
				}
				i++;
				continue;
			}
			
		}
		ans++;
		distance++;
	}
	cout << ans << '\n';
	return 0;
}
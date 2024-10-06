#include <iostream>
#include <vector>

using namespace std;
int n;
pair<char, char> node[26];	// node[i] = {a,b} : 부모는 i(number,'A'일경우 0), 왼쪽자식은 a(char), 오른쪽자식은 b(char)

void preorder(char v) {	// 전위순회
	if (v == '.')
		return;

	cout << v;
	preorder(node[v - 'A'].first);
	preorder(node[v - 'A'].second);
}
void inorder(char v) {	// 중위순회
	if (v == '.')
		return;

	inorder(node[v - 'A'].first);
	cout << v;
	inorder(node[v - 'A'].second);
}
void postorder(char v) {	//후위순회
	if (v == '.')
		return;

	postorder(node[v - 'A'].first);
	postorder(node[v - 'A'].second);
	cout << v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	char parent, left, right;
	for (int i = 0; i < n; i++) {
		cin >> parent >> left >> right;
		int idx = parent - 'A';
		node[idx].first = left;
		node[idx].second = right;
	}

	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A');
	

	return 0;
}

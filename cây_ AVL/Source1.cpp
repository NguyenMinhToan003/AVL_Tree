#include"Header.h"
void main() {
	tree root;
	root = NULL;
	int a = 0;
	while (1) {
		cout << "\n1.Them ";
		cout << "\n2.Duyet ";
		cout << "\n3.Xoa ";
		cout << "\nLua chon : ";
		int option;
		cin >> option;
		if (option == 1) {
			cout << "\nNhap so :";
			cin >> a;
			insertNode(root, a);
		}
		else if (option == 2) {
			cout << "\nDuyet Node Left Right ";
			duyet_NodeLeftRight(root);
			cout << "\nDuyet Left Node Right ";
			duyet_LeftNodeRight(root);
			cout << "\nDuyet Left Right Node ";
			duyet_LeftRightNode(root);

		}
		else if (option == 3) {
			cout << "\nNhap so : ";
			cin >> a;
			deleteNode(root, a)
		}
	}
}
#include <set>;
#include <iostream>;
using namespace std;
int main() {
	setlocale(0, "");
	int id, z;
	set <int> akk;
	set <int> ::iterator it;
	while (true) {
		id = rand() % 100 + 1;
		if (akk.find(id) == akk.end()) {
			cout << "Новый аккаунт " << id << endl;
			akk.insert(id);
		}
		else {
			cout << "Повторное использование аккаунта " << id << endl;
			break;
		}
	}
}
HANDLE fH;
FILETIME creationTime;
SYSTEMTIME sysTime;
fH = CreateFile(L"C:\\boot.ini", GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
if (fH != INVALID_HANDLE_VALUE)
{
	GetFileTime(fH, &creationTime, 0, 0);
	FileTimeToSystemTime(&creationTime, &sysTime);
	std::cout << sysTime.wDay << "." << sysTime.wMonth << "." << sysTime.wYear <<
		" " << sysTime.wHour << ":" << sysTime.wHour << std::endl;
	CloseHandle(fH);
}
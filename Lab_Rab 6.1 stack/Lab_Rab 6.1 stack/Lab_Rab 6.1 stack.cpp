#include <iostream>
#include <stack>
using namespace std;

bool balanced(const std::string& s) {
    std::stack<char> stack;
    for (char c : s) {
        switch (c) {

        case '(': stack.push(')'); break;
        case '[': stack.push(']'); break;
        case '{': stack.push('}'); break;
        case '<': stack.push('>'); break;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stack.empty() || stack.top() != c) { // если стэк пуст 
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    return stack.empty();
}

void test(const std::string& s) {
    
    std::cout << '"' << s << "\" " << (balanced(s) ? "yes" : "no") << '\n';
}

int main()
{
    setlocale(LC_ALL, "rus");
	cout << "Введите выражение в скобках";
    string s;
    cin >> s;
    test(s); 

} 


    
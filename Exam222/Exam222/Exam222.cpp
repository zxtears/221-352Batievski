#include <iostream>
#include <vector>  //буду делать через векторыне массивы, проходил на stepik

using namespace std;

class Game {
private:
    string mainWord; // главное слово
    int n; // количество игроков(так же отвечает за назначение очков)
    vector<unsigned int> players; // очки игроков (unsigned int это беззнаковое целое число) 
    vector<string> words; // слова которые уже были

    void Start(string word, int players); //метод
    bool Turn(string word); //метод (ход)
public:  //чтобы можно было использовать game в любой функции 
    Game() {}; //конструктор 
    ~Game() {}; //деструктор

    void Play();
};

void Game::Start(string word, int players) { // :: идентификатор класса (пространство имен)
    mainWord = word; // назначить главное слово
    n = 0;
    for (int i = 0; i < players; i++)
        this->players.push_back(0); // добавить всех игроков, push back нужен чтобы вставить новый элемент в конец массива тем самымы увеличить его размерность
    //Указатель this хранит адрес определённого объекта класса (players)
}

bool Game::Turn(string word) {
    if (word.length() > mainWord.length()) { // если введеное слово больше по длинне чем главное то это уже неверно
        return false;
    }

    for (int i = 0; i < words.size(); i++) { // проверяем было ли введено уже это слово
        if (words[i] == word)
            return false;
    }
    bool f = true; // флаг нужен чтобы понимать что буква не была найдена
    for (int i = 0; i < word.length() && f; i++) { // берем букву в веденном слове (&& логическое И)
        f = false;
        for (int j = 0; j < mainWord.length(); j++) { // ищем букву в главноем слове
            if (word[i] == mainWord[j]) f = true;
        }

    }
    if (!f) { // если буква не была найдена то слово неверное
        return false;
    }
    if (n == players.size()) n = 0;// если мы дошли до количества игроков то обнуляем счетчик
    players[n]++; // n-ому игроку добавляем бал
    n++; // переходим к следующему игроку
    words.push_back(word); // сохраняем слово (добовляем через пуш)
    return true;
}

void Game::Play() {
    int n;
    string s;
    cout << "Введите количество игроков: ";
    cin >> n;
    cout << "Введите главное слово: ";
    cin >> s;
    Start(s, n);
    while (1) {  // единица означает что цикл бесконечный, его можно прервать только брейком 
        s = "";
        cout << "0-выход" << endl << "Введите слово: ";
        cin >> s;
        if (s == "0") {
            for (int i = 0; i < n; i++) // выводим очки всех игроков
                cout << "Игрок " << i + 1 << ": " << players[i] << endl;
            break; //
        }
        if (Turn(s)) {
            cout << "Вы ввели верное слово" << endl;
        }
        else {
            cout << "Вы ввели неверное слово" << endl;
        }
    }
}

int main() {
    setlocale(0, "");
    Game g;

    g.Play();
    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <Windows.h>

using namespace std;

class Player {
private:
    string name;
    int score;

public:
    Player(string n) : name(n), score(0) {}

    string getName() {
        return name;
    }

    int getScore() {
        return score;
    }

    void addPoint() {
        score++;
    }

    string guess() {
        string choice;
        while (true) {
            cout << name << ", выбери 'Орел' или 'Решка': ";
            cin >> choice;


            string lowered = choice;
            transform(lowered.begin(), lowered.end(), lowered.begin(), ::tolower);

            if (lowered == "орел" || lowered == "решка") (lowered == "Орел" || lowered == "Решка") ; 
            
            {

                return (lowered == "орел") ? "Орел" : "Решка";
            }


            vector<string> insults = {
                "Ты чё, с луны упал?",
                "Сконцентрируйся, гений!",
                "Ты точно умеешь читать?",
                "Шутник выискался! Пиши нормально."
            };
            int r = rand() % insults.size();
            cout << insults[r] << " Попробуй ещё раз.\n";
        }
    }
};

class Game {
private:
    vector<Player> players;

public:
    Game(vector<string> names) {
        for (string& n : names)
            players.push_back(Player(n));
    }

    void start() {
        srand(time(0));
        bool gameOver = false;
        while (!gameOver) {
            for (Player& p : players) {
                string guess = p.guess();
                string result = flipCoin();
                cout << "Выпало: " << result << endl;

                if (guess == result) {
                    p.addPoint();
                    cout << p.getName() << " угадал! Счёт: " << p.getScore() << endl;
                }
                else {
                    cout << p.getName() << " не угадал.\n";
                }

                if (p.getScore() >= 3) {
                    cout << "\n🎉 ПОБЕДИЛ: " << p.getName() << " с " << p.getScore() << " очками!\n";
                    gameOver = true;
                    break;
                }

                cout << endl;
            }
        }
    }

    string flipCoin() {
        return (rand() % 2 == 0) ? "Орел" : "Решка";
    }
};

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<string> names = { "Игрок1", "Игрок2", "Игрок3" };
    Game game(names);
    game.start();
    return 0;
}
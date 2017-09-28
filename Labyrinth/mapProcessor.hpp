#include <SFML\Graphics.hpp>
#include <fstream>
#include <cassert>
#include <list>

using namespace std;

class MapProcessor{
private:
	const unsigned coinsLimit = 50, heartsLimit = 2;

	void wipeLoot(vector<sf::String> &map){
		for (unsigned i = 1; i < 23; i++)
			for (unsigned j = 1; j < 23; j++)
				if (map[i][j] == '2' || map[i][j] == 'h') map[i][j] = '0';
	}

	unsigned countCoins(vector<sf::String> &map){
		unsigned temp = 0;
		for (unsigned i = 1; i < 23; i++)
			for (unsigned j = 1; j < 23; j++)
				if (map[i][j] == '2') temp++;
#ifdef Debug
		printf("Current coins %u\n", temp);
#endif
		return temp;
	}

	unsigned countHearths(vector<sf::String> &map){
		unsigned temp = 0;
		for (unsigned i = 1; i < 23; i++)
			for (unsigned j = 1; j < 23; j++)
				if (map[i][j] == 'h') temp++;
#ifdef Debug
		printf("Current hearts %u\n", temp);
#endif
		return temp;
	}

	void randomMapGenerate(unsigned currentCoinsCount, unsigned currentHearthsCount, vector<sf::String> &map){ //Генерация
		int randomElementX = 0;
		int randomElementY = 0;
		srand(time(0));
		unsigned limitCoins = coinsLimit - currentCoinsCount;
		unsigned limitHearths = heartsLimit - currentHearthsCount;

		while (limitCoins > 0){
			randomElementX = 1 + rand() % 23;
			randomElementY = 1 + rand() % 23;

			if (map[randomElementY][randomElementX] == '0') {
				map[randomElementY][randomElementX] = '2';
				limitCoins--;
			}
		}

		while (limitHearths > 0){
			randomElementX = 1 + rand() % 23;
			randomElementY = 1 + rand() % 23;

			if (map[randomElementY][randomElementX] == '0') {
				map[randomElementY][randomElementX] = 'h';
				limitHearths--;
			}
		}
	}

public:
	MapProcessor(){}

	unsigned getCoinsLimit(){ return coinsLimit; }

	void proceedMap(int &restart, vector<sf::String> &map){
		if (restart > 0) wipeLoot(map);
		randomMapGenerate(countCoins(map), countHearths(map), map);
	}
};

const int HEIGHT_MAP = 24;
const int WIDTH_MAP = 24;

std::vector<sf::String> mapC;

/*std::vector<string> map3 = {
"111111111111111111111111",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"100000000000000000000001",
"111111111111111111111111",
};*/

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include "Character.h"

    class Enemy : public Character {
    public:
        Enemy(const std::string& filename);//kreator przyjmujący nazwe pliku z którego trzeba wcztać teksturę,
        // również od razu wywołuje metode wczytującą teksturę, którą odziedzicza z kalsy character
        void Init() override;//Funckja nie zwraca zmiennych, ustawia teksturę sprite'a, ustawia pozycje oraz skalę sprite'a
};


#endif //GAME_ENEMY_H


#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include "Character.h"

    class Enemy : public Character {
    public:
        Enemy(const std::string& filename);

        /**
        *Init sets the sprite texture and position.
        */
        void Init() override;
};


#endif //GAME_ENEMY_H

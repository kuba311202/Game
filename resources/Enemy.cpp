#include "Enemy.h"
Enemy::Enemy(const std::string& filename): Character(filename){//kreator
   LoadTexture(filename);//wczytywanie pliku
}

void Enemy::Init(){
    sprite.setTexture(texture);//ustawianie tekstury sprite'a.
    sprite.scale(1,1);//ustawianie skali sprite'a.
    sprite.setPosition(630, 580);//ustawianie pozycji sprite'a.
}

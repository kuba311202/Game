
#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H
#include <iostream>
#include <string>
#include <vector>


#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"


class Character {
public:
    bool defOn;
    sf::Texture texture;
    sf::Sprite sprite;

    /**
    *LoadTexture check if the file exists and then load it and saves it into parameter texture.
    *
    *@param filename contains name of the file that will be loaded.
    */
    void LoadTexture(const std::string& filename);

    /**
    *Init sets the sprite texture and position.
    */
    virtual void Init();

    /**
    *draw draws loaded texture in the window.
    *
    *@param window contains in which window function will work.
    */
    void draw(sf::RenderWindow& window) const;

    /**
    *SetHealth change current health of Player to the given value.
    *
    *@param newHealth contains value that will be switched to Player's health.
    */
    void SetHealth(int newHealth);

    /**
    *SetMana change current mana of Player to the given value.
    *
    *@param newMana contains value that will be switched to Player's mana.
    */
    void SetMana(int newMana);

    /**
    *SetMana change current mana of Player to the given value.
    *
    *@param newArmor contains value that will be switched to Player's armor.
    *@param newMagicResist contains value that will be switched to Player's magicResist.
    *@param newDefOn contains value that determine if Player used defend last turn.
    */
    void SetResist(int newArmor,int newMagicResist,bool newDefOn);
    /**
    *GetHealth return Player's current health value.
    *
    *@return Player's 'health'.
    */
    int GetHealth() const;

    /**
    *GetMana return Player's current mana value.
    *
    *@return Player's 'mana'.
    */
    int GetMana() const;

    /**
    *GetAttack return Player's current attack value.
    *
    *@return Player's 'attack'.
    */
    int GetAttack() const;

    /**
    *GetHealth return Player's current armor value.
    *
    *@return Player's 'armor'.
    */
    int GetArmor() const;

    /**
    *GetHealth return Player's current magicResist value.
    *
    *@return Player's 'magicResist'.
    */
    int GetMagicResist() const;

    /**
    *GetHealth return Player's character class name.
    *
    *@return Player's character class name.
    */
    const std::string &getName() const;

    Character(const std::string& filename);
    virtual ~Character();
private:
    int maxHealth;
    int health;
    int mana;
    int attack;
    int armor;
    int magicResist;
    std::string name;
};


#endif //GAME_CHARACTER_H

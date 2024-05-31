
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
    //publiczne zmienne
    bool defOn;
    sf::Texture texture;
    sf::Sprite sprite;

    //publiczne funkcje

    void LoadTexture(const std::string& filename);/*Funkcja nic nie zwraca, pobiera ciąg znaków który jest nazwą pliku,
    tekstury którą ma wczytać, wywołuje również funkcję init*/
    virtual void Init();//Funkcja nic nie zwraca, oraz nie przyjmuje żadnych wartości, ustawia sprite'a na podstawie wcześniej wczytanej tekstury oraz ustawia pozycje sprite'a
    void draw(sf::RenderWindow& window) const;//Funkcja nic nie zwraca, przyjmuje okno w którym następnie ma "narysować" postać ze wcześniej wczytanego sprite'a

    void SetHealth(int newHealth);//Funkcja nie zwraca zmiennych, przyjmuje liczbe którą potem zmienia na hp postaci, jeśli hp przekroczy maksymalne hp, to ustawiane jest  to maksymalne
    void SetMana(int newMana);//Funkcja nie zwraca zmiennych, przyjmuje liczbe którą potem zmienia na manę postaci
    void SetResist(int newArmor,int newMagicResist,bool newDefOn);/*Funkcja nic nie zwraca,przyjmuje 3 wartosci, dwa inty oraz bool
    inty zmieniaja warość pancerza oraz odpornosci na magię postaci, a bool stwierdza czy obrona została użyta, lub tez nie */
    int GetHealth() const;//Funckja zwraca int, którym jest hp postaci
    int GetMana() const;//Funckja zwraca int, którym jest mana postaci
    int GetAttack() const;//Funckja zwraca int, którym jest atak postaci
    int GetArmor() const;//Funckja zwraca int, którym jest obrona postaci
    int GetMagicResist() const;//Funckja zwraca int, którym jest odporność na magię postaci

    const std::string &getName() const;//Funkcja zwraca ciąg znaków którym jest nazwa postaci(klasa postaci)

    Character(const std::string& filename);
    virtual ~Character();
private:
    //prywatne zmienne
    int maxHealth;
    int health;
    int mana;
    int attack;
    int armor;
    int magicResist;
    std::string name;
};


#endif //GAME_CHARACTER_H

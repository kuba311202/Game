
#ifndef GAME_BACKGROUND_H
#define GAME_BACKGROUND_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>

class BackGround {
public:
    void LoadTexture(const std::string& filename);//Funkcja nic nie zwraca, pobiera ciąg znaków który jest nazwą pliku, tekstury którą ma wczytać
    void draw(sf::RenderWindow& window) const; //Funkcja nic nie zwraca, przyjmuje okno w którym następnie ma "narysować" tło ze wcześniej wczytanego sprite'a
    void Init(); //Funkcja nic nie zwraca, oraz nie przyjmuje żadnych wartości, ustawia sprite'a na podstawie wcześniej wczytanej tekstury oraz ustawia pozycje sprite'a

    sf::Texture texture;
    sf::Sprite sprite;

    BackGround(const std::string& filename);
private:

};



#endif //GAME_BACKGROUND_H

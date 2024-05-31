
#ifndef GAME_FONTS_H
#define GAME_FONTS_H


#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <string>

class Fonts {
public:
    Fonts(const std::string& content,float x,float y);

    sf::Font font;
    sf::Text text;

    void Init(const std::string& content,float x,float y);//funckja nic nie zwraca, przyjmuje 3 zmienne, pierwsza z nich określa zawartość tekstu, a dwie kolejne jego pozycje
    //funkcja ustawia właściwości tekstu jak kolor, grubosć obramówki, kolor obramówki, wielkośc liter
    void draw(sf::RenderTarget& target) const;//Funkcja nic nie zwraca, przyjmuje miejsce w którym bedziemy "rysować" napis
    void LoadFont();//Funkcja nic nie zwraca, pobiera ciąg znaków który jest nazwą pliku, czcionki którą ma wczytać

private:

};




#endif //GAME_FONTS_H

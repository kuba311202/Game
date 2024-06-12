
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

    /**
    *Init sets properties of text.
    *
    *@param content contains what text will be displayed.
    *@param x contains coordinates of x on which text will start being displayed.
    *@param y contains coordinates of y on which text will start being displayed.
    */
    void Init(const std::string& content,float x,float y);

    /**
    *draw write the text.
    *
    *@param target contains where the text will be writen.
    */
    void draw(sf::RenderTarget& target) const;

    /**
    *LoadFont check if the file exists and then load it and saves it into parameter texture.
    */
    void LoadFont();

private:

};




#endif //GAME_FONTS_H

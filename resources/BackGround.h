
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

    /**
    *LoadTexture check if the file exists and then load it and saves it into parameter texture.
    *
    *@param filename contains name of the file that will be loaded.
    */
    void LoadTexture(const std::string& filename);

    /**
    *draw draws loaded texture in the window.
    *
    *@param window contains in which window function will work
    */
    void draw(sf::RenderWindow& window) const;

    /**
    *Init sets the sprite texture and position.
    */
    void Init();
    sf::Texture texture;
    sf::Sprite sprite;

    BackGround(const std::string& filename);
private:

};



#endif //GAME_BACKGROUND_H

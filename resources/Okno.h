
#ifndef GAME_OKNO_H
#define GAME_OKNO_H


#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <random>

#include "SFML/Graphics.hpp"
#include <SFML/System/Clock.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include "Enemy.h"
#include "Character.h"
#include "BackGround.h"
#include "Fonts.h"
#include "windows.h"




class Okno {
public:
    Okno();
    std::vector <std::shared_ptr<Character>> UnitsTab;

    /**
     *GameLoop creates Render window and runs render functions.
     *
    */
    void GameLoop();
private:

    /**
    *Update lets player pick character's class, and checks who's turn it is.
    *
    *@param window contains in which window function will work
   */
    void Update(sf::RenderWindow& window);

    /**
    *Render displays informations about player's and pc's stats.
    *
    *@param window contains in which window function will work
    */
    void Render(sf::RenderWindow& window);

    /**
    *PlayerTurn let Player do choose what action they want to do.
    *
    *@param window contains in which window function will work
    */
    void PlayerTurn(sf::RenderWindow& window);

    /**
    *PcTurn decides what action Pc will do.
    *
    *@param window contains in which window function will work
    */
    void PcTurn(sf::RenderWindow& window);

    /**
    *RenderMenu displays background and text in menu.
    *
    *@param window contains in which window function will work
    */
    void RenderMenu(sf::RenderWindow& window);

    /**
    *RenderOver displays background depending on who won the fight.
    *
    *@param window contains in which window function will work
    */
    void RenderOver(sf::RenderWindow& window);

    /**
    *CreateUnits add units for Player and Pc to UnitsTab.
    */
    void CreateUnits();

    int actualEnemy;
    int actualPlayer;
    bool userTurn;
    bool menuOpen;
    bool gameOver;
    bool pcLost;
    bool playerLost;


};

#endif //GAME_OKNO_H

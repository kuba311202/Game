
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
    std::vector <std::shared_ptr<Character>> UnitsTab;//wektor w którym przechowywane są postacie
    void GameLoop();//Funkcja nic nie zwraca, ustawia właściwosci tworzonego przez nas okna, oraz obsługuje wyswietlanie dobrego okna(menu, walki, lub końca gry)
private:
    void Update(sf::RenderWindow& window);//Funkcja nic nie zwraca, w oknie menu, pozwala wybrać nam klasę, a w oknie walki, sprawdza czyja jest tura
    void Render(sf::RenderWindow& window);//Funkcja nic nie zwraca, pobiera zmienne, które następnie wyświetla na ekranie, oraz wyswietla tło
    void PlayerTurn(sf::RenderWindow& window);//pobiera zmienne, dzieki którym następnie odpowiada za całą logike podczas tury gracza
    // (pozwala wybierać co gracz zrobi, oraz oblicza wszelkie obrażenia/utratę życia/utrate many/leczenie/obrone)
    void PcTurn(sf::RenderWindow& window);//pobiera zmienne, dzieki którym następnie odpowiada za całą logike podczas tury "komputera"
    // (losuje jaka akcję komputer podejmie, oraz oblicza wszelkie obrażenia/utratę życia/utrate many/leczenie/obrone)
    void RenderMenu(sf::RenderWindow& window);//Wyswietla napisy w ekranie menu oraz tło
    void RenderOver(sf::RenderWindow& window);//wyswietla tło w ekranie końca gry zależnie od tego kto wygrał
    void CreateUnits();//tworzy naszą postać oraz postać przeciwnika
    //prywatne zmienne
    int actualEnemy;
    int actualPlayer;
    bool userTurn;
    bool menuOpen;
    bool gameOver;
    bool pcLost;
    bool playerLost;


};

#endif //GAME_OKNO_H

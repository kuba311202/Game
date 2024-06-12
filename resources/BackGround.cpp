#include "BackGround.h"

BackGround::BackGround(const std::string& filename){ //Kreator clasy, wymaga nazwy pliku.
    LoadTexture(filename); //Wczytanie tekstury o podanej nazwie.
    Init();//wywołanie funkcji.
};

void BackGround::LoadTexture(const std::string& filename){//metoda wczytujaca tekstury, wymaga nazwy pliku.
    if (!texture.loadFromFile("../sprites/"+filename+".png")) { //Sprawdza czy istnieje plik o podanej nazwie z końcówką png.
        std::cerr << "Texture error player \n"; //obsługa błędów.
    }
}

void BackGround::Init(){
    sprite.setTexture(texture);//ustawia teksturę obiektu na tą wczytaną w poprzedniej metodzie.
    sprite.setPosition(0, 0); //ustawia miejsce rozpoczęcia się tekstury.
}

void BackGround::draw(sf::RenderWindow& window) const {
    window.draw(sprite);//rysuje sprite'a w naszym oknie.
}


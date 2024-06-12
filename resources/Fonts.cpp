#include "Fonts.h"


Fonts::Fonts(const std::string& content,float x,float y){//konstruktor, trzeba podać zawartość oraz miejsce wyświetlenia
    LoadFont();//wczytywanie czcionki
    Init(content,x,y);//wywołanie funkcji i przekazanie argumentów odpowiadajacyh za położenie napisu
}

void Fonts::Init(const std::string& content,float x,float y){//inicjalizacja napisu, trzeba podać zawartość oraz miejsce wyświetlenia
    text.setFont(font);//ustawia czcionkę
    text.setFillColor(sf::Color::Black);//kolor czcionki
    text.setOutlineColor(sf::Color::White);//kolor obramówki
    text.setString(content);//zawartość tekstu
    text.setPosition(x,y);//pozycja czcionki
    text.setOutlineThickness(1.5);//grubość obramówki
    text.setCharacterSize(60);//wielkość liter

}

void Fonts::draw(sf::RenderTarget& target) const {
    target.draw(text);//rysuje czcionkę w oknie
}

void Fonts::LoadFont(){
    if(!font.loadFromFile("../fonts/FontFile.TTF")){//sprawdza czy czcionka o takie jaznwie istnieje
        std::cerr << "Font error \n";//błąd
    }
}


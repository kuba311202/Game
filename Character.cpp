
#include "Character.h"


Character::Character(const std::string& filename){//kreator klasy
    if(filename=="Warrior"){//Ustawia statystyki na podstawie nazwy podanej w kostruktorze
        maxHealth=50;
        health=50;
        mana = 10;
        attack = 10;
        armor=5;
        magicResist=4;
        defOn=false;
        name="Warrior";
    } else if(filename=="Hunter"){//Ustawia statystyki na podstawie nazwy podanej w kostruktorze
        maxHealth=35;
        health=35;
        mana = 5;
        attack = 15;
        armor=4;
        magicResist=3;
        defOn=false;
        name="Hunter";
    } else if(filename=="Mage"){//Ustawia statystyki na podstawie nazwy podanej w kostruktorze
        maxHealth=30;
        health=30;
        mana = 20;
        attack = 5;
        armor=3;
        magicResist=5;
        defOn=false;
        name="Mage";
    }
    LoadTexture(filename);//wczytuje sprite'a na podstawie nazwy podanej w konstruktorze.
}

Character::~Character()= default; //Destruktor.

void Character::LoadTexture(const std::string& filename){//metoda wczytujaca sprite'a, wymaga nazwy.
    if (!texture.loadFromFile("../sprites/"+filename+".png")) { //sprawdza czy plik o podanej nazwie istnieje.
        std::cerr << "Texture error player \n";//obsługa błędów.
    }
    Init();//wywołuje metodę Init.
}

void Character::Init(){
    sprite.setTexture(texture);//ustawia teksturę sprite'a.
    sprite.setOrigin(0,0); //ustawia z jakiego miejsca zacząć wyświetlać sprite'a.
    sprite.setPosition(0, 0);//ustawia pozycję sprite'a.
}

void Character::draw(sf::RenderWindow& window) const{
    window.draw(sprite);//rysuje sprite'a w naszym oknie.
}

void Character::SetHealth(int newHealth) {//Setter życia postaci, podajemy nową wartość życia.
    if (newHealth < 0) {//Jeżeli podana wartość jest mniejsza od zera.

    } else {
    health = newHealth;
    if (health > maxHealth) {//jeśli życie przewyższyło by maksymalna wartość, to zmnniejszamy je do maksymalnej wartosci
        health = maxHealth;
    }
}
}

void Character::SetMana(int newMana){ //setter many postaci, podajemy nowa wartość many
    mana=newMana;
}
void Character::SetResist(int newArmor,int newMagicResist, bool newDefOn){//Setter obrony, podajemy nową wartość obrony, obrony na magie, oraz czy zwiekszylismy obrone
    armor=newArmor;
    magicResist=newMagicResist;
    defOn=newDefOn;
}

//gettery

int Character::GetHealth() const{
    return health;
}
int Character::GetMana() const{
    return mana;
}
int Character::GetAttack() const {
    return attack;
}
int Character::GetArmor() const{
    return armor;
}
int Character::GetMagicResist() const{
    return magicResist;
}
const std::string &Character::getName() const {
    return name;
}




#include "Okno.h"

Okno::Okno(){
    srand(time(NULL));//Seed
    CreateUnits();//wywołuje funkcję
    //zmienne
    menuOpen=true;
    userTurn = true;
    gameOver = false;
    pcLost=false;
    playerLost=false;
    actualPlayer = 0;
    actualEnemy = rand() % 3 + 3;
}

void Okno::GameLoop() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Okno");//Tworzy okno
    window.setFramerateLimit(120);//limit fpsów

    while (window.isOpen()) {//zamykanie okna przy kliknięciu x
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //Update
        Update(window);

        //Render
        if (menuOpen) {
            RenderMenu(window);
        } else if (gameOver) {
            RenderOver(window);
        } else {
        Render(window);
    }
    }
}

void Okno::Update(sf::RenderWindow& window){
    //wybór klasy postaci
        if(menuOpen && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)){
            actualPlayer=0;
            menuOpen = false;
        }else if(menuOpen && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)){
            actualPlayer=1;
            menuOpen = false;
        }else if(menuOpen && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)){
            actualPlayer=2;
            menuOpen = false;
        }
        //sprawdzanie czyja jest tura
        if(userTurn){
            PlayerTurn(window);
        }else{
            PcTurn(window);
        }
    }


void Okno::Render(sf::RenderWindow& window){
//pobranie zmiennych do wyświetlenia
    int myHealth = UnitsTab[actualPlayer]->GetHealth();
    int enemyHealth = UnitsTab[actualEnemy]->GetHealth();
    int myMana = UnitsTab[actualPlayer]->GetMana();
    int enemyMana = UnitsTab[actualEnemy]->GetMana();
    std::string myName = UnitsTab[actualPlayer]->getName();
    std::string enemyName = UnitsTab[actualEnemy]->getName();

    window.clear(sf::Color::Black);
    BackGround("Background").draw(window);//Wyświetlenie tła

    UnitsTab[actualEnemy]->draw(window);
//wyświetlanie życia oraz nazwy klasy
    std::string playerinfo = (myName+"\n HP:"+std::to_string(int(myHealth))+"\n MP:"+std::to_string(int(myMana)));
    Fonts(playerinfo,50, 850).draw(window);

    std::string enemyinfo = (enemyName+"\n HP:"+std::to_string(int(enemyHealth))+"\n MP:"+ std::to_string(int(enemyMana)));
    Fonts(enemyinfo,1050, 650).draw(window);
    window.display();
}
void Okno::RenderMenu(sf::RenderWindow& window){
    window.clear(sf::Color::Black);
    //wyświetlanie tła oraz napisów o wybraniu klasy
    BackGround("Menu").draw(window);
    Fonts("Press 1,2 or 3 to choose a class.",300,200).draw(window);
    Fonts("Press 1 to choose Warrior.",500,300).draw(window);
    Fonts("Press 2 to choose Hunter.",500,400).draw(window);
    Fonts("Press 3 to choose Mage.",500,500).draw(window);
    window.display();
}

void Okno::RenderOver(sf::RenderWindow& window) {
    window.clear(sf::Color::Blue);
    //wyswietlanie tekstu zależnie od tego kto wygra
    if (pcLost) {
        BackGround("Win").draw(window);
    }else{
        BackGround("Lost").draw(window);
    }
    window.display();
}

void Okno::CreateUnits(){//Tworzenie klas naszej postaci i przeciwników
    UnitsTab.push_back(std::make_shared<Character>("Warrior"));
    UnitsTab.push_back(std::make_shared<Character>("Hunter"));
    UnitsTab.push_back(std::make_shared<Character>("Mage"));

    UnitsTab.push_back(std::make_shared<Enemy>("Warrior"));
    UnitsTab.push_back(std::make_shared<Enemy>("Hunter"));
    UnitsTab.push_back(std::make_shared<Enemy>("Mage"));
}


void Okno::PlayerTurn(sf::RenderWindow& window){//Tura gracza
    //Pobieranie zmiennych
    int myHealth = UnitsTab[actualPlayer]->GetHealth();
    int myMana = UnitsTab[actualPlayer]->GetMana();
    int myAttack = UnitsTab[actualPlayer]->GetAttack();
    int myArmor = UnitsTab[actualPlayer]->GetArmor();
    int myMagicResist = UnitsTab[actualPlayer]->GetMagicResist();
    int enemyHealth = UnitsTab[actualEnemy]->GetHealth();
    int enemyMana = UnitsTab[actualEnemy]->GetMana();
    int enemyAttack = UnitsTab[actualEnemy]->GetAttack();
    int enemyArmor = UnitsTab[actualEnemy]->GetArmor();
    int enemyMagicResist = UnitsTab[actualEnemy]->GetMagicResist();
    std::string myName = UnitsTab[actualPlayer]->getName();
    std::string enemyName = UnitsTab[actualEnemy]->getName();
    UnitsTab[actualEnemy]->sprite.setColor(sf::Color(255,255,255));//resetowanie koloru sprite'a do podstawowego
    //Sprawdzenie czy gracz uzył obrony w ostatniej turze
    if(UnitsTab[actualPlayer]->defOn){
        //usuniecie efektu obrony i ustawienie użycia jej na fałsz
        myArmor-=5;
        myMagicResist-=5;
        UnitsTab[actualPlayer]->SetResist(myArmor,myMagicResist,false);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){//atakowanie
        enemyHealth=enemyHealth-ceil(myAttack-enemyArmor*0.5);//obliczanie obrażeń
        UnitsTab[actualEnemy]->SetHealth(enemyHealth);//ustawienie życia
        UnitsTab[actualEnemy]->sprite.setColor(sf::Color(140,0,0));//zmiana koloru sprite'a od przeciwnika na czerwony
        userTurn=false;//koniec tury
    }else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){//leczenie
        int manaCost = 5;//koszt
        if(myMana<manaCost){//jeżeli nie ma wystarczająco many nic sie nie dzieje
        }else {
            UnitsTab[actualPlayer]->SetHealth(myHealth + 10);//zwiekszenie zycia gracz
            UnitsTab[actualPlayer]->SetMana(myMana - manaCost);//obniżenie many gracza
            userTurn = false;//koniec tury
        }

    }else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)){//obrona
        UnitsTab[actualPlayer]->SetResist(myArmor+5,myMagicResist+5,true);//zwiekszenie odpornosci
        userTurn=false;//koniec tury
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::XButton1)) {//rzucenie czaru
        int manaCost = 5;//koszt many
        if(myMana<manaCost){//sprawdzenie czy gracz ma manę

        }else {
            int spellDamage = 10;//obrażenia
            enemyHealth = enemyHealth - ceil(spellDamage - enemyMagicResist * 0.5);//obliczanie obrażeń
            UnitsTab[actualPlayer]->SetMana(myMana - manaCost);//zmniejszenie many gracza
            UnitsTab[actualEnemy]->SetHealth(enemyHealth);//zmniejszenie życia przeciwnika
            UnitsTab[actualEnemy]->sprite.setColor(sf::Color(140, 0, 0));//ustawienie koloru sprite'a przeciwnika na czerwony
            userTurn = false;//koniec tury
        }
    }
    //przecwnik przegrał
    if(enemyHealth<=0) {
        pcLost=true;
        gameOver=true;
    }
}


void Okno::PcTurn(sf::RenderWindow& window){//to co u gracza
    int myHealth = UnitsTab[actualPlayer]->GetHealth();
    int myMana = UnitsTab[actualPlayer]->GetMana();
    int myAttack = UnitsTab[actualPlayer]->GetAttack();
    int myArmor = UnitsTab[actualPlayer]->GetArmor();
    int myMagicResist = UnitsTab[actualPlayer]->GetMagicResist();
    int enemyHealth = UnitsTab[actualEnemy]->GetHealth();
    int enemyMana = UnitsTab[actualEnemy]->GetMana();
    int enemyAttack = UnitsTab[actualEnemy]->GetAttack();
    int enemyArmor = UnitsTab[actualEnemy]->GetArmor();
    int enemyMagicResist = UnitsTab[actualEnemy]->GetMagicResist();
    std::string myName = UnitsTab[actualPlayer]->getName();
    std::string enemyName = UnitsTab[actualEnemy]->getName();
    UnitsTab[actualEnemy]->sprite.setColor(sf::Color(255,255,255));
    if(UnitsTab[actualEnemy]->defOn){
        UnitsTab[actualEnemy]->SetResist(myArmor-5,myMagicResist-5,false);

    }
    //losowanie co zrobi przeciwnik
    int random_num=rand()%3;
    if(random_num==0) {//leczenie
        if (enemyMana < 5) {//sprawdza czy komputer ma potrzebną mane
            if (ceil(enemyAttack - myArmor * 0.5 < 0)) {//sprawdzanie czy atak zadał wiecej niz 0
                userTurn = true;//tura gracza
            } else {//atak
            myHealth = myHealth - ceil(enemyAttack - myArmor * 0.5);
            UnitsTab[actualPlayer]->SetHealth(myHealth);
            userTurn = true;
        }
        } else {
        int manaCost = 5;
        UnitsTab[actualEnemy]->SetHealth(enemyHealth + 10);
        UnitsTab[actualEnemy]->SetMana(enemyMana - manaCost);
        userTurn = true;
        UnitsTab[actualEnemy]->sprite.setColor(sf::Color(0, 140, 0));
    }
    }
    else if(random_num==1){//obrona
        UnitsTab[actualEnemy]->SetResist(myArmor+5,myMagicResist+5,true);
        userTurn = true;
    }else if(random_num==2){//atak
        myHealth = myHealth - ceil(enemyAttack - myArmor * 0.5);
        UnitsTab[actualPlayer]->SetHealth(myHealth);
        userTurn = true;
    }
    //gracz przegrywa
    if(myHealth<=0){
        playerLost=true;
        gameOver=true;
    }

}
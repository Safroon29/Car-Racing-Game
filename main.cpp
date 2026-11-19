#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<sstream>
using namespace sf;
using namespace std;
class Car {
protected:
    Sprite sprite;
    float speed;
public:
    Car(Texture &texture, float x, float y, float s) {
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setScale(0.2f, 0.2f);
        speed = s;

    }
    virtual void move(float dt) = 0;
    Sprite& getSprite() { return sprite; }
    FloatRect getBounds() { return sprite.getGlobalBounds(); }
    float getSpeed() { return speed; }
    void setSpeed(float s) { speed = s; }
};
class Player : public Car {
private:
    float minSpeed = 100;
    float maxSpeed = 800;
public:
    Player(Texture &texture, float x, float y)
        : Car(texture, x, y, 200.0f) {}
    void move(float dt) override {
        if (Keyboard::isKeyPressed(Keyboard::Up))
            speed += 800 * dt;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            speed -= 600 * dt;
        if (speed < minSpeed) speed = minSpeed;
         if (speed > maxSpeed) speed = maxSpeed;

        if (Keyboard::isKeyPressed(Keyboard::Left))
            sprite.move(-speed * dt, 0);
        if (Keyboard::isKeyPressed(Keyboard::Right))
            sprite.move(speed * dt, 0);
    }
    void keepInside(int width) {
        if (sprite.getPosition().x < 0)
            sprite.setPosition(0, sprite.getPosition().y);
        if (sprite.getPosition().x > width - sprite.getGlobalBounds().width)
            sprite.setPosition(width - sprite.getGlobalBounds().width, sprite.getPosition().y);
    }
    void reset() {
        sprite.setPosition(150, 450);
        speed = 200;
    }
};
class Enemy : public Car {
public:
    Enemy(Texture &texture, float x, float y, float s)
        : Car(texture, x, y, s) {}

    void move(float dt) override {
        sprite.move(0, speed * dt);
    }
    void reset(int width, int offsetY) {
        sprite.setPosition(30 + rand() % (width - 100), -offsetY);
    }
};
class Game {
private:
    RenderWindow window;
    Texture playerTex, enemyTex, roadTex;
    Sprite road;
    Player *player;
    vector<Enemy> enemies;
    float gameSpeed;
    float roadY;
    int score;
    int finalTime;  

    Clock gameClock;
    Clock deltaClock;
    Font font;
    Text scoreText, timeText, speedText;
    bool gameOver;
    Text gameOverText, finalScoreText, finalTimeText;

public:
    Game() : window(VideoMode(400, 600), "SAFROON NISHA - THE LEGEND AND HER GAME") {

        window.setFramerateLimit(60);
        playerTex.loadFromFile("assets/player_car.png");
        enemyTex.loadFromFile("assets/enemy_car.png");
        roadTex.loadFromFile("assets/road.png");
        road.setTexture(roadTex);
        road.setScale(
            (float)window.getSize().x / roadTex.getSize().x,
            (float)window.getSize().y / roadTex.getSize().y
        );
        player = new Player(playerTex, 150, 450);
        for (int i = 0; i < 4; i++) {
            enemies.push_back(
                Enemy(enemyTex, 50 + rand() % 250, -i * 150, 120)
            );
        }
        font.loadFromFile("assets/arial.ttf");

        scoreText.setFont(font);
        timeText.setFont(font);
        speedText.setFont(font);

        scoreText.setCharacterSize(18);
        timeText.setCharacterSize(18);
        speedText.setCharacterSize(18);

        scoreText.setFillColor(Color::White);
        timeText.setFillColor(Color::White);
        speedText.setFillColor(Color::White);

        scoreText.setPosition(10, 10);
        timeText.setPosition(10, 35);
        speedText.setPosition(10, 60);

        gameOverText.setFont(font);
        finalScoreText.setFont(font);
        finalTimeText.setFont(font);

        gameOverText.setCharacterSize(30);
        finalScoreText.setCharacterSize(20);
        finalTimeText.setCharacterSize(20);

        gameOverText.setFillColor(Color::Red);
        finalScoreText.setFillColor(Color::White);
        finalTimeText.setFillColor(Color::White);

        gameOverText.setPosition(80, 250);
        finalScoreText.setPosition(90, 300);
        finalTimeText.setPosition(90, 330);

        resetGame();
    }
    void resetGame() {
        score = 0;
        finalTime = 0;
        gameSpeed = 200;
        roadY = 0;
        gameOver = false;

        gameClock.restart();
        player->reset();

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].reset(window.getSize().x, i * 150);
        }
    }
    void run() {
        while (window.isOpen()) {
            float dt = deltaClock.restart().asSeconds();
            handleEvents();
            update(dt);
            render();
        }
    }
    void handleEvents() {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }if (gameOver && Keyboard::isKeyPressed(Keyboard::R)) {
            resetGame();
        }
    }
    void update(float dt) {
        if (!gameOver) {
            player->move(dt);
            player->keepInside(window.getSize().x);

            gameSpeed = player->getSpeed();
            for (auto &e : enemies) {
                e.setSpeed(gameSpeed);
                e.move(dt);
                if (e.getSprite().getPosition().y > window.getSize().y) {
                    e.reset(window.getSize().x, 100);
                    score++;
                }
                if (player->getBounds().intersects(e.getBounds())) {
                    gameOver = true;
                    finalTime = gameClock.getElapsedTime().asSeconds(); 
                }
            }
            roadY += gameSpeed * dt;
            if (roadY >= window.getSize().y)
                roadY = 0;
        }
        /*scoreText.setString("Score: " + to_string(score));
        if (!gameOver)
            timeText.setString("Time: " + to_string((int)gameClock.getElapsedTime().asSeconds()));
        else
            timeText.setString("Time: " + to_string(finalTime));
        speedText.setString("Speed: " + to_string((int)player->getSpeed()));
        if (gameOver) {
            gameOverText.setString("GAME OVER");
            finalScoreText.setString("Final Score: " + to_string(score));
            finalTimeText.setString("Time: " + to_string(finalTime) + "s (Press R)");
        }
    }*/
       stringstream ss1, ss2, ss3, ss4, ss5;
        ss1 << "Score: " << score;
        scoreText.setString(ss1.str());
        if (!gameOver) {
            ss2 << "Time: " << (int)gameClock.getElapsedTime().asSeconds();
            timeText.setString(ss2.str());
        } else {
            ss2 << "Time: " << finalTime;
            timeText.setString(ss2.str());
        }
        ss3 << "Speed: " << (int)player->getSpeed();
        speedText.setString(ss3.str());
        if (gameOver) {
            gameOverText.setString("GAME OVER");
            ss4 << "Final Score: " << score;
            finalScoreText.setString(ss4.str());
            ss5 << "Time: " << finalTime << "s (Press R)";
            finalTimeText.setString(ss5.str());
        }
    }
    void render() {
        window.clear();
        road.setPosition(0, roadY);
        window.draw(road);
        road.setPosition(0, roadY - window.getSize().y);
        window.draw(road);

        if (!gameOver) {
            window.draw(player->getSprite());
            for (auto &e : enemies)
                window.draw(e.getSprite());

            window.draw(scoreText);
            window.draw(timeText);
            window.draw(speedText);
        } else {
            window.draw(gameOverText);
            window.draw(finalScoreText);
            window.draw(finalTimeText);
        }

        window.display();
    }
};
int main() {
    Game game;
    game.run();
    return 0;
}
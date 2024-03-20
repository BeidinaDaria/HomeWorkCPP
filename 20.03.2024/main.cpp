#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "test sfml");
    int soccetSize = 50;
    std::vector<sf::RectangleShape> field;
    for (int i = 0; i <= window.getSize().y - soccetSize; i += soccetSize) {
        for (int j = 0; j <= window.getSize().x - soccetSize; j += soccetSize) {
            sf::RectangleShape soccet;
            soccet.setOutlineThickness(1);
            soccet.setOutlineColor(sf::Color::Black);
            soccet.setSize(sf::Vector2f(soccetSize, soccetSize));
            soccet.setPosition(sf::Vector2f(j, i));
            field.push_back(soccet);
        }
    }
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& shape : field) {
                    if ((mousePos.x >= shape.getPosition().x) &&
                        (mousePos.x <= (shape.getPosition().x + shape.getSize().x)) &&
                        (mousePos.y >= shape.getPosition().y) &&
                        (mousePos.y <= (shape.getPosition().y + shape.getSize().y))) {
                        sf::Color color = shape.getFillColor();
                        if (color == sf::Color::White)
                            shape.setFillColor(sf::Color::Black);
                        else
                            shape.setFillColor(sf::Color::White);
                    }
                }

            }

        }
        window.clear(sf::Color::White);
        for (auto  el: field) {
            window.draw(el);
        }
        window.display();
    }

    return 0;
}
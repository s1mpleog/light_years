#include <iostream>
#include <SFML/Graphics.hpp>

int main(void) {
    sf::RenderWindow renderWindow{sf::VideoMode(100, 100), "testing window"};
    std::cout << "Hello World!" << std::endl;
    return 0;
}

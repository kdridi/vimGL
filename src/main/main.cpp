#include <SFML/Graphics.hpp>

#define SCALE 16
#define WIDTH (80 * SCALE)
#define HEIGHT (45 * SCALE)

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "vimGL");
    
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            // "Escape Key pressed" event: we close the window
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        break;
                }
        }
        
        window.clear(sf::Color::Black);
        window.display();
    }
    
    return 0;
}

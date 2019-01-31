#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define SCALE 32
#define WIDTH (80 * SCALE)
#define HEIGHT (45 * SCALE)

#include "assets.hpp"
#include "keyboard/handler.hpp"
#include "game/context.hpp"

/*/

class command_keyboard_event
{
public:
    command_keyboard_event(std::stringstream& stream);
    
    bool handle(const sf::Event::KeyEvent& key);
    
    inline void enable() { _enabled = true; }
    inline void disable() { _enabled = false; }
    inline bool enabled() const { return _enabled; }

private:
    bool _enabled;
    std::stringstream& _stream;
};

command_keyboard_event::command_keyboard_event(std::stringstream& stream)
: _enabled(false)
, _stream(stream)
{
}

bool command_keyboard_event::handle(const sf::Event::KeyEvent& key)
{
    if (enabled() == false)
        return false;

    if (sf::Keyboard::A <= key.code && key.code <= sf::Keyboard::Z) {
        _stream << static_cast<char>(key.code + 'a');
        return true;
    }
    
    if(key.code == sf::Keyboard::BackSpace) {
        const std::string& str{_stream.str()};
        if (str.empty() == false)
        {
            _stream.str("");
            _stream << str.substr(0, str.length() - 1);
        }
        return true;
    }

    return false;
}
 /*/

int main() {
    game::context& ctx{game::context::instance()};
    
    sf::Font font;
    if (!font.loadFromFile(assets::instance().font_path("ponderosa.ttf")))
        std::exit(84);

    sf::Vector2i text_padding{10, 10};
    
    
    std::stringstream text_stream;
    
    keyboard::handler keyboard_handler;

    /*/
     command_keyboard_event cke(text_stream);
    cke.enable();

     /*/
    
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(SCALE);
    text.setPosition(0 + text_padding.x, HEIGHT - (text.getCharacterSize() + text_padding.y));
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "vimGL");
    
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed)
                keyboard_handler.handle(event.key);
            
            
            /*/
            // "Escape Key pressed" event: we close the window
            if (event.type == sf::Event::KeyPressed)
            {
                if (cke.handle(event.key) == false)
                {
                    if(event.key.code == sf::Keyboard::Return) {
                        std::cout << text_stream.str() << std::endl;
                        text_stream.str("");
                        cke.disable();
                    } else if(event.key.code == sf::Keyboard::SemiColon && event.key.shift == true) {
                        cke.enable();
                    } else {
                        switch (event.key.code) {
                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                            default:
                                std::cerr << "event.key.code: " << event.key.code << std::endl;
                                break;
                        }
                    }
                }
            }
             /*/
        }
        
        if (ctx.is_running() == false)
        {
            window.close();
            continue;
        }

        window.clear(sf::Color::Black);

        if (true)
        {
            text.setString(ctx.macro_get());
            window.draw(text);
        }

        window.display();
    }
    
    return 0;
}

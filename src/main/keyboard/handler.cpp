//
//  handler.cpp
//  vimGL
//
//  Created by Karim DRIDI on 31/01/2019.
//

#include "handler.hpp"
#include "../game/context.hpp"

#include <iostream>

void keyboard::mode::normal::handler::handle(handler_state_context& ctx, const sf::Event::KeyEvent& key)
{
    switch (key.code) {
        case sf::Keyboard::Escape:
        {
            std::cout << "EXIT!!!" << std::endl;
            game::context::instance().exit();
            break;
        }
        case sf::Keyboard::Space:
        {
            std::cout << "MODE: normal -> player" << std::endl;
            ctx.setState<keyboard::mode::player::handler>();
            break;
        }
        case sf::Keyboard::SemiColon:
        {
            if (key.shift == true)
            {
                std::cout << "MODE: normal -> macro" << std::endl;
                ctx.setState<keyboard::mode::macro::handler>();
                game::context::instance().macro_add_character(':');
            }
            break;
        }
        default:
            break;
    }
}

void keyboard::mode::player::handler::handle(handler_state_context& ctx, const sf::Event::KeyEvent& key)
{
    switch (key.code) {
        case sf::Keyboard::Escape:
        {
            std::cout << "MODE: player -> normal" << std::endl;
            ctx.setState<keyboard::mode::normal::handler>();
            break;
        }
        default:
            break;
    }
}

void keyboard::mode::macro::handler::handle(handler_state_context& ctx, const sf::Event::KeyEvent& key)
{
#define case_character(_code, _shiftF, _shiftT) \
    case sf::Keyboard::_code: \
    { \
        game::context::instance().macro_add_character(key.shift ? _shiftT : _shiftF); \
        break; \
    }
    
    switch (key.code) {
        case_character(A, 'a', 'A')
        case_character(B, 'b', 'B')
        case_character(C, 'c', 'C')
        case_character(D, 'd', 'D')
        case_character(E, 'e', 'E')
        case_character(F, 'f', 'F')
        case_character(G, 'g', 'G')
        case_character(H, 'h', 'H')
        case_character(I, 'i', 'I')
        case_character(J, 'j', 'J')
        case_character(K, 'k', 'K')
        case_character(L, 'l', 'L')
        case_character(M, 'm', 'M')
        case_character(N, 'n', 'N')
        case_character(O, 'o', 'O')
        case_character(P, 'p', 'P')
        case_character(Q, 'q', 'Q')
        case_character(R, 'r', 'R')
        case_character(S, 's', 'S')
        case_character(T, 't', 'T')
        case_character(U, 'u', 'U')
        case_character(V, 'v', 'V')
        case_character(W, 'w', 'W')
        case_character(X, 'x', 'X')
        case_character(Y, 'y', 'Y')
        case_character(Z, 'z', 'Z')
        case_character(Space, ' ', ' ')
        case_character(Num1, '1', '!')
        case_character(Num2, '2', '@')
        case_character(Num3, '3', '#')
        case_character(Num4, '4', '$')
        case_character(Num5, '5', '%')
        case_character(Num6, '6', '^')
        case_character(Num7, '7', '&')
        case_character(Num8, '8', '*')
        case_character(Num9, '9', '(')
        case_character(Num0, '0', ')')
        case_character(Dash, '-', '_')
        case_character(Equal, '=', '+')
        case sf::Keyboard::Escape:
        {
            std::cout << "MODE: macro -> normal" << std::endl;
            ctx.setState<keyboard::mode::normal::handler>();
            game::context::instance().macro_clear();
            break;
        }
        case sf::Keyboard::Return:
        {
            std::cout << "MODE: macro -> normal" << std::endl;
            ctx.setState<keyboard::mode::normal::handler>();
            game::context::instance().macro_execute();
            break;
        }
        default:
            break;
    }
}

keyboard::handler::handler()
: _context()
{
    _context.setState<keyboard::mode::normal::handler>();
}

void keyboard::handler::handle(const sf::Event::KeyEvent& key)
{
    _context._state->handle(_context, key);
}

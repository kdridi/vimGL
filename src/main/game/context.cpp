//
//  context.cpp
//  vimGL
//
//  Created by Karim DRIDI on 31/01/2019.
//

#include "context.hpp"

#include <sstream>
#include <iostream>

namespace game
{
    namespace ns_context
    {
        static std::stringstream macro_stream;
        static bool running = true;
    }
};

game::context& game::context::instance()
{
    static game::context instance;
    return instance;
}

game::context& game::context::macro_add_character(char ch)
{
    ns_context::macro_stream << ch;
    return (*this);
}

game::context& game::context::macro_delete_last_character()
{
    if (ns_context::macro_stream.str().size() > 2)
    {
        ns_context::macro_stream.str(ns_context::macro_stream.str().substr(0, ns_context::macro_stream.str().size() - 1));
    }
    return (*this);
}

std::string game::context::macro_get()
{
    return (ns_context::macro_stream.str());
}

game::context& game::context::macro_clear()
{
    ns_context::macro_stream.str("");
    return (*this);
}

game::context& game::context::macro_execute()
{
    std::cout << "EXECUTE : " << macro_get().substr(1) << std::endl;
    macro_clear();
    return (*this);
}

bool game::context::is_running()
{
    return (ns_context::running);
}

game::context& game::context::exit()
{
    ns_context::running = false;
    return (*this);
}

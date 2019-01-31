//
//  context.hpp
//  vimGL
//
//  Created by Karim DRIDI on 31/01/2019.
//

#ifndef context_hpp
#define context_hpp

#include <string>

namespace game
{
    class context
    {
    public:
        static context& instance();
        
    public:
        context& macro_add_character(char ch);
        context& macro_delete_last_character();
        context& macro_clear();
        context& macro_execute();
        std::string macro_get();
        
    public:
        bool is_running();
        context& exit();

    private:
        context() {}
        ~context() {}
        context(context const&);
    };
}

#endif /* context_hpp */

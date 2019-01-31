//
//  handler.hpp
//  vimGL
//
//  Created by Karim DRIDI on 31/01/2019.
//

#ifndef handler_hpp
#define handler_hpp

#include <SFML/Window/Event.hpp>
#include <memory>

namespace keyboard
{
    class handler_state_context;
    class handler;

    class handler_state
    {
    public:
        handler_state() {}
        virtual ~handler_state() {}
        
    private:
        handler_state(handler_state const&);
        
    public:
        virtual void handle(handler_state_context& ctx, const sf::Event::KeyEvent& key) = 0;
    };
    
    class handler_state_context
    {
    public:
        handler_state_context() {}
        virtual ~handler_state_context() {}
        
    private:
        handler_state_context(handler_state_context const&);
        
    public:
        template<class handler_state, class... handler_state_args>
        void setState(handler_state_args&&... args) {
            _state = std::make_unique<handler_state>(std::forward<handler_state_args>(args)...);
        }
        
    private:
        std::unique_ptr<handler_state> _state;
        friend class handler;
    };
    
    class handler
    {
    public:
        handler();
        virtual ~handler() {}
        
    private:
        handler(handler const&);
        
    public:
        void handle(const sf::Event::KeyEvent& key);
        
    private:
        handler_state_context _context;
    };
    
    namespace mode
    {
        namespace normal
        {
            class handler : public handler_state
            {
            public:
                handler() {}
                virtual ~handler() {}
                
            private:
                handler(handler const&);
                
            public:
                void handle(handler_state_context& ctx, const sf::Event::KeyEvent& key) override;
            };
        }

        namespace player
        {
            class handler : public handler_state
            {
            public:
                handler() {}
                virtual ~handler() {}
                
            private:
                handler(handler const&);
                
            public:
                void handle(handler_state_context& ctx, const sf::Event::KeyEvent& key) override;
            };
        }

        namespace macro
        {
            class handler : public handler_state
            {
            public:
                handler() {}
                virtual ~handler() {}
                
            private:
                handler(handler const&);
                
            public:
                void handle(handler_state_context& ctx, const sf::Event::KeyEvent& key) override;
            };
        }
    }
    
    
}

#endif /* handler_hpp */

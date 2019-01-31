//
//  assets.hpp
//  vimGL
//
//  Created by Karim DRIDI on 31/01/2019.
//

#ifndef assets_hpp
#define assets_hpp

#include <string>

class assets
{
public:
    static assets& instance();
    
public:
    std::string const& font_path(std::string const& name);
    
private:
    assets();
    assets(assets const& other);
};

#endif /* assets_hpp */

//
//  assets.cpp
//  vimGL
//
//  Created by Karim DRIDI on 31/01/2019.
//

#include "assets.hpp"

#include <sstream>
#include <memory>
#include <map>

namespace ns_assets
{
    static auto root_path = []() { return "/Volumes/epitech/git/github.com/kdridi/vimGL.git/assets"; };
    static std::map<std::string, std::unique_ptr<std::string const>> font_path;
}

assets::assets()
{
}

assets& assets::instance()
{
    static assets instance;
    return instance;
}

std::string const& assets::font_path(std::string const& name)
{
    if (ns_assets::font_path.find(name) == ns_assets::font_path.end())
    {
        std::stringstream s;
        s << ns_assets::root_path();
        s << "/fonts/";
        s << name;
        ns_assets::font_path[name] = std::make_unique<std::string>(s.str());
    }
    
    return *(ns_assets::font_path[name]);
}

#include <rise/style.hpp>

rise::style::style()
    : property_stroke_width_(*this, "stroke-width")
{

}

rise::style::style(Glib::ustring const &_str)
    : rise::style()
{
    parse(_str);
}

Glib::ustring rise::style::str() const
{
    Glib::ustring str;
    for(auto itr = p_map.begin(); itr != p_map.end(); ++itr)
    {
	if(itr != p_map.begin()) str += ';';
	str += itr->first + ':' + itr->second;
    }
    return str;
}

void rise::style::parse(Glib::ustring const &_str)
{
    std::istringstream in(_str.raw());
    in >> std::skipws;
    
    while(in.good())
    {
	std::string str;
	std::getline(in, str, ';');
	auto pos = str.find(':');
	if(pos != std::string::npos) p_map[str.substr(0, pos)] = str.substr(pos + 1);
    }
}

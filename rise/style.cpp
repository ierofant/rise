#include <rise/style.hpp>

rise::style::style()
    : property_fill_(*this, "fill"),
      property_stroke_(*this, "stroke"),
      property_stroke_width_(*this, "stroke-width", 1)
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

bool rise::style::has_property(Glib::ustring const &_property) const
{
    return p_map.find(_property) != p_map.end();
}

Glib::ustring rise::style::get_property_value(Glib::ustring const &_property) const
{
    Glib::ustring retval;
    auto itr = p_map.find(_property);
    if(itr != p_map.end()) retval = itr->second;
    return retval;
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

void rise::style::set_property_value(Glib::ustring const &_property, Glib::ustring const &_value)
{
    p_map[_property] = _value;
}

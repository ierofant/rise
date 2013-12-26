#include <rise/attribute.hpp>

rise::attribute_base::attribute_base(rise::element &_element,
				     Glib::ustring const &_name,
				     Glib::ustring const &_prefix)
    : element(_element),
      name(_name),
      prefix(_prefix)
{

}

Glib::ustring const& rise::attribute_base::get_name() const
{
    return name;
}

Glib::ustring const& rise::attribute_base::get_prefix() const
{
    return prefix;
}


template<>
auto rise::attribute<Glib::ustring>::get() const -> typename attribute<Glib::ustring>::value_type
{
    return element.get_attribute_value(name, prefix);
}

template<>
void rise::attribute<Glib::ustring>::set(typename attribute<Glib::ustring>::value_type const &_value)
{
    element.set_attribute(name, _value, prefix);
}

template<>
auto rise::attribute<rise::points>::get() const -> typename attribute<rise::points>::value_type
{
    rise::points points;
    auto value = element.get_attribute_value(name, prefix);
    std::istringstream in(value);
    while(in.good())
    {
	char sym;
	double x, y;
	in >> x >> sym >> y;
	points.push_back(point(x, y));
    }
    return points;
}

template<>
void rise::attribute<rise::points>::set(typename attribute<rise::points>::value_type const &_value)
{
    std::ostringstream out;
    for(auto itr = _value.begin(); itr != _value.end(); ++itr)
    {
	if(itr != _value.begin()) out << ' ';
	out << itr->x << ',' << itr->y;
    }
    element.set_attribute(name, out.str(), prefix);
}

template<>
auto rise::attribute<rise::style>::get() const -> typename rise::attribute<rise::style>::value_type
{
    rise::style style(element.get_attribute_value(name, prefix));
    return style;    
}
    
template<>
void rise::attribute<rise::style>::set(typename attribute<rise::style>::value_type const &_value)
{
    element.set_attribute(name, _value.str(), prefix);
}

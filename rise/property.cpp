#include <rise/property.hpp>
#include <rise/style.hpp>

rise::property_base::property_base(rise::style &_style, Glib::ustring const &_name)
    : style(_style),
      name(_name)
{

}

bool rise::property_base::inherit() const
{
    return !style.has_property(name);
}

Glib::ustring rise::property_base::get_value() const
{
    return style.get_property_value(name);
}

void rise::property_base::set_value(Glib::ustring const &_value)
{
    return style.set_property_value(name, _value);
}

template<>
void rise::property<Gdk::Color>::set(typename rise::property<Gdk::Color>::value_type const &_value)
{
    set_value(_value.to_string());
}

template<>
auto rise::property<Gdk::Color>::get() const -> typename rise::property<Gdk::Color>::value_type
{
    return Gdk::Color(get_value());
}

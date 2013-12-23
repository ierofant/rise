#include <rise/property.hpp>

template<>
auto rise::property<Glib::ustring>::get() const -> typename property<Glib::ustring>::value_type
{
    return element.get_attribute_value(name, prefix);
}

template<>
void rise::property<Glib::ustring>::set(typename property<Glib::ustring>::value_type const &_value)
{
    element.set_attribute(name, _value, prefix);
}

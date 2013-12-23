#ifndef RISE_PROPERTY_HPP_INCLUDED
#define RISE_PROPERTY_HPP_INCLUDED

#include <type_traits>
#include <rise/element.hpp>

namespace rise
{
    template<typename T>
    class property
    {
	public:
	    typedef T value_type;

	public:
	    property(rise::element &_element,
		     Glib::ustring const &_name,
		     value_type const &_default_value = value_type())
		: element(_element),
		  name(_name),
		  default_value(_default_value)
	    {

	    }

	    property(rise::element &_element,
		     Glib::ustring const &_name,
		     Glib::ustring const &_prefix,
		     value_type const &_default_value = value_type())
		: property(_element, _name, _default_value)
	    {
		prefix = _prefix;
	    }

	public:
	    value_type get() const
	    {
		value_type value;
		auto str = element.get_attribute_value(name, prefix);
		std::istringstream in(str.raw());
		in >> value;
		return value;
	    }
	    void set(value_type const &_value)
	    {
		std::ostringstream out;
		out << _value;
		element.set_attribute(name, out.str(), prefix);
	    }
	    void reset() {element.remove_attribute(name, prefix);}

	private:
	    rise::element &element;
	    Glib::ustring name, prefix;
	    value_type default_value;
    };
}

#endif //RISE_PROPERTY_HPP_INCLUDED

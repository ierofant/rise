#ifndef RISE_ATTRIBUTE_HPP_INCLUDED
#define RISE_ATTRIBUTE_HPP_INCLUDED

#include <rise/element.hpp>
#include <rise/points.hpp>
#include <rise/style.hpp>

namespace rise
{
    class attribute_base
    {
	public:
	    attribute_base(rise::element &_element,
			   Glib::ustring const &_name,
			   Glib::ustring const &_prefix = Glib::ustring());

	public:
	    Glib::ustring const& get_name() const;
	    Glib::ustring const& get_prefix() const;

	protected:
	    rise::element &element;
	    Glib::ustring const name, prefix;
    };

    template<typename T>
    class attribute : public attribute_base
    {
	public:
	    typedef T value_type;

	public:
	    attribute(rise::element &_element,
		     Glib::ustring const &_name,
		     value_type const &_default_value = value_type())
		: attribute_base(_element, _name),
		  default_value(_default_value)
	    {

	    }

	    attribute(rise::element &_element,
		     Glib::ustring const &_name,
		     Glib::ustring const &_prefix,
		     value_type const &_default_value = value_type())
		: attribute_base(_element, _name, prefix),
		  default_value(_default_value)
	    {

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
	    value_type default_value;
    };

    template<>
    auto attribute<Glib::ustring>::get() const -> typename attribute<Glib::ustring>::value_type;

    template<>
    void attribute<Glib::ustring>::set(typename attribute<Glib::ustring>::value_type const &_value);

    template<>
    auto attribute<points>::get() const -> typename attribute<points>::value_type;

    template<>
    void attribute<points>::set(typename attribute<points>::value_type const &_value);

    template<>
    auto attribute<style>::get() const -> typename attribute<style>::value_type;
    
    template<>
    void attribute<style>::set(typename attribute<style>::value_type const &_value);
}

#endif //RISE_ATTRIBUTE_HPP_INCLUDED

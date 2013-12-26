#ifndef RISE_PROPERTY_HPP_INCLUDED
#define RISE_PROPERTY_HPP_INCLUDED

#include <glibmm/ustring.h>
#include <gdkmm/color.h>

namespace rise
{
    class style;
    class property_base
    {
	public:
	    property_base(rise::style &_style, Glib::ustring const &_name);

	public:
	    bool inherit() const;
	    Glib::ustring get_value() const;
	    void set_value(Glib::ustring const &_value);

	protected:
	    rise::style &style;
	    Glib::ustring const name;
    };

    template<typename T>
    class property : public property_base
    {
	public:
	    typedef T value_type;

	public:
	    property(rise::style &_style, Glib::ustring const &_name, value_type const &_default_value = value_type())
		: property_base(_style, _name),
		  internal_value(_default_value)
	    {

	    }

	public:
	    value_type get() const;
	    void set(value_type const &_value);

	private:
	    value_type get_internal() const;
	    void set_internal(value_type const &_value);

	private:
	    value_type internal_value;
    };

    template<typename T>
    auto property<T>::get() const -> typename property<T>::value_type
    {
	std::istringstream in(get_value(name));
	value_type value;
	in >> value;
	return value;
    }

    template<typename T>
    void property<T>::set(typename property<T>::value_type const &_value)
    {
	std::ostringstream out;
	out << _value;
	set_value(name, _value);
    }

    template<typename T>
    auto property<T>::get_internal() const -> typename property<T>::value_type
    {
	return inherit() ? internal_value : get();
    }

    template<typename T>
    void property<T>::set_internal(value_type const &_value)
    {
	internal_value = _value;
    }

    template<>
    void property<Gdk::Color>::set(typename property<Gdk::Color>::value_type const &_value);

    template<>
    auto property<Gdk::Color>::get() const -> typename property<Gdk::Color>::value_type;
}

#endif //RISE_PROPERTY_HPP_INCLUDED

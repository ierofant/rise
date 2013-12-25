#ifndef RISE_PROPERTY_HPP_INCLUDED
#define RISE_PROPERTY_HPP_INCLUDED

#include <glibmm/ustring.h>

namespace rise
{
    class style;
    class property_base
    {
	public:
	    property_base(rise::style &_style, Glib::ustring const &_name);

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
	    property(rise::style &_style, Glib::ustring const &_name)
		: property_base(_style, _name)
	    {

	    }
    };
}

#endif //RISE_PROPERTY_HPP_INCLUDED

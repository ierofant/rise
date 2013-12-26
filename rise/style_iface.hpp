#ifndef RISE_STYLE_IFACE_HPP_INCLUDED
#define RISE_STYLE_IFACE_HPP_INCLUDED

#include <rise/attribute.hpp>

namespace rise
{
    class style_iface
    {
	public:
	    style_iface(rise::element &_element);

	public:
	    void draw(Cairo::RefPtr<Cairo::Context> const &_cr);

	private:
	    rise::element &element;
	    rise::attribute<rise::style> attribute_style_;
    };
}

#endif //RISE_STYLE_IFACE_HPP_INCLUDED

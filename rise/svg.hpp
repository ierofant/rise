#ifndef RISE_SVG_HPP_INCLUDED
#define RISE_SVG_HPP_INCLUDED

#include <rise/element.hpp>
#include <rise/attribute.hpp>

namespace rise
{
    class svg : public element
    {
	public:
	    svg(_xmlNode *_node);
	    virtual ~svg() = default;

	private:
	    rise::attribute<Glib::ustring> attribute_version;
	    rise::attribute<double> attribute_width;
	    rise::attribute<double> attribute_height;
    };
}

#endif //RISE_SVG_HPP_INCLUDED

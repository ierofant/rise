#ifndef RISE_SVG_HPP_INCLUDED
#define RISE_SVG_HPP_INCLUDED

#include <rise/element.hpp>
#include <rise/property.hpp>

namespace rise
{
    class svg : public element
    {
	public:
	    svg(_xmlNode *_node);
	    virtual ~svg() = default;

	private:
	    rise::property<Glib::ustring> property_version;
	    rise::property<double> property_width;
	    rise::property<double> property_height;
    };
}

#endif //RISE_SVG_HPP_INCLUDED

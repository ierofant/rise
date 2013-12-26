#ifndef RISE_POLY_HPP_INCLUDED
#define RISE_POLY_HPP_INCLUDED

#include <rise/style_iface.hpp>

namespace rise
{
    template<bool closed = true>
    class poly : public rise::element
    {
	public:
	    poly(_xmlNode *_node)
		: rise::element(_node),
		  attribute_points_(*this, "points"),
		  style_iface(*this)
	    {

	    }

	public:
	    rise::points get_points() const {attribute_points_.get();}

	protected:
	    void draw(Cairo::RefPtr<Cairo::Context> const &_cr)
	    {
		if(_cr)
		{
		    auto points = get_points();
		    for(auto itr = points.begin(); itr != points.end(); ++itr)
		    {
			if(itr == points.begin()) _cr->move_to(itr->x, itr->y);
			else _cr->line_to(itr->x, itr->y);
		    }

		    if(closed) _cr->line_to(points.front().x, points.front().y);
		}
	    }

	private:
	    rise::attribute<rise::points> attribute_points_;
	    rise::style_iface style_iface;
    };

    typedef poly<true> polygon;
    typedef poly<false> polyline;
}

#endif //RISE_POLY_HPP_INCLUDED

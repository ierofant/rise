#ifndef RISE_RECT_HPP_INCLUDED
#define RISE_RECT_HPP_INCLUDED

#include <rise/property.hpp>

namespace rise
{
    class rect : public rise::element
    {
	public:
	    rect(_xmlNode *_node);
	    virtual ~rect() = default;

	public:
	    double get_x() const;
	    double get_y() const;
	    double get_width() const;
	    double get_height() const;

	protected:
	    void draw_vfunc(Cairo::RefPtr<Cairo::Context> const &_cr);
	    
	private:
	    rise::property<double> property_x, property_y, property_width, property_height;
    };
}

#endif //RISE_RECT_HPP_INCLUDED

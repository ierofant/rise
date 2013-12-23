#include <rise/rect.hpp>

rise::rect::rect(_xmlNode *_node)
    : rise::element(_node),
      property_x(*this, "x", 0),
      property_y(*this, "y", 0),
      property_width(*this, "width", 0),
      property_height(*this, "height", 0)
{

}

double rise::rect::get_x() const
{
    return property_x.get();
}

double rise::rect::get_y() const
{
    return property_y.get();
}

double rise::rect::get_width() const
{
    return property_width.get();
}

double rise::rect::get_height() const
{
    return property_height.get();
}

#include <iostream>
void rise::rect::draw_vfunc(Cairo::RefPtr<Cairo::Context> const &_cr)
{
    if(_cr)
    {
	double x = get_x();
	double y = get_y();
	double width = get_width();
	double height = get_height();
	if(width == 0 || height == 0)
	{
std::cout << x << '\t' << y << '\t' << width << '\t' << height << std::endl;
	     _cr->rectangle(x, y, width, height);
	}
    }
}

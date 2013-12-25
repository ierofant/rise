#include <rise/rect.hpp>

rise::rect::rect(_xmlNode *_node)
    : rise::element(_node),
      attribute_x(*this, "x", 0),
      attribute_y(*this, "y", 0),
      attribute_width(*this, "width", 0),
      attribute_height(*this, "height", 0)
{

}

double rise::rect::get_x() const
{
    return attribute_x.get();
}

double rise::rect::get_y() const
{
    return attribute_y.get();
}

double rise::rect::get_width() const
{
    return attribute_width.get();
}

double rise::rect::get_height() const
{
    return attribute_height.get();
}

void rise::rect::draw_vfunc(Cairo::RefPtr<Cairo::Context> const &_cr)
{
    if(_cr)
    {

    }
}

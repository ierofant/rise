#ifndef RISE_RECT_HPP_INCLUDED
#define RISE_RECT_HPP_INCLUDED

#include <rise/attribute.hpp>

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
	    void draw_vfunc(Cairo::RefPtr<Cairo::Context> const &_cr) override;
	    
	private:
	    rise::attribute<double> attribute_x, attribute_y, attribute_width, attribute_height;
    };
}

#endif //RISE_RECT_HPP_INCLUDED

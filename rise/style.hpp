#ifndef RISE_STYLE_HPP_INCLUDED
#define RISE_STYLE_HPP_INCLUDED

#include <map>
#include <rise/property.hpp>

namespace rise
{
    class style
    {
	public:
	    style();
	    style(Glib::ustring const &_str);

	public:
	    Glib::ustring str() const;
	    void parse(Glib::ustring const &_str);

	private:
	    typedef std::map<Glib::ustring, Glib::ustring> property_map;

	private:
	    property_map p_map;
	    rise::property<double> property_stroke_width_;
    };
}

#endif //RISE_STYLE_HPP_INCLUDED

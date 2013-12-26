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
	    bool has_property(Glib::ustring const &_property) const;
	    Glib::ustring get_property_value(Glib::ustring const &_property) const;
	    void parse(Glib::ustring const &_str);
	    void set_property_value(Glib::ustring const &_property, Glib::ustring const &_value);

	private:
	    typedef std::map<Glib::ustring, Glib::ustring> property_map;

	private:
	    property_map p_map;
	    rise::property<Gdk::Color> property_fill_;
	    rise::property<Gdk::Color> property_stroke_;
	    rise::property<double> property_stroke_width_;
	    
    };
}

#endif //RISE_STYLE_HPP_INCLUDED

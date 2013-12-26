#ifndef RISE_SVG_WIDGET_HPP_INCLUDED
#define RISE_SVG_WIDGET_HPP_INCLUDED

#include <gtkmm/widget.h>
#include <rise/document.hpp>

namespace rise
{
    class svg_widget : public Gtk::Widget
    {
	public:
	    svg_widget();
	    virtual ~svg_widget() = default;

	public:
	    void set_source_file(Glib::ustring const &_filename);

	protected:
	    virtual void on_realize() override;
	    virtual void on_unrealize() override;
	    virtual void get_preferred_width_vfunc(int &_minimum_width, int &_natural_width) const override;
	    virtual void get_preferred_height_vfunc(int &_minimum_height, int &_natural_height) const override;
	    virtual void on_size_allocate(Gtk::Allocation &_allocation) override;
	    virtual bool on_draw(Cairo::RefPtr<Cairo::Context> const &_cr) override;

	private:
	    Glib::RefPtr<Gdk::Window> window;
	    rise::document doc;
    };
}

#endif //RISE_SVG_WIDGET_HPP_INCLUDED

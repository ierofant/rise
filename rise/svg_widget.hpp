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
	    void on_realize() override;
	    void on_unrealize() override;
	    void on_size_allocate(Gtk::Allocation &_allocation) override;
	    bool on_draw(Cairo::RefPtr<Cairo::Context> const &_cr) override;

	private:
	    Glib::RefPtr<Gdk::Window> window;
	    rise::document doc;
    };
}

#endif //RISE_SVG_WIDGET_HPP_INCLUDED

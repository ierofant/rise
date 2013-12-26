#include <cstring>
#include <rise/svg_widget.hpp>
#include <rise/parser.hpp>

rise::svg_widget::svg_widget()
    : Glib::ObjectBase(typeid(*this))
{
    set_has_window(true);
}

void rise::svg_widget::set_source_file(Glib::ustring const &_filename)
{
    rise::parser p(doc);
    p.parse_file(_filename);
    queue_resize();
}

void rise::svg_widget::on_realize()
{
    set_realized();
    if(!window)
    {
	auto allocation = get_allocation();

	GdkWindowAttr attrs;
	std::memset(&attrs, 0, sizeof(attrs));
	attrs.x = allocation.get_x();
	attrs.y = allocation.get_y();
	attrs.width = allocation.get_width();
	attrs.height = allocation.get_height();
	attrs.event_mask = get_events() | Gdk::EXPOSURE_MASK;
	attrs.window_type = GDK_WINDOW_CHILD;
	attrs.wclass = GDK_INPUT_OUTPUT;

	window = Gdk::Window::create(get_parent_window(), &attrs, GDK_WA_X | GDK_WA_Y);
	set_window(window);
	window->set_user_data(gobj());
    }
}

void rise::svg_widget::on_unrealize()
{
    window.reset();
    Gtk::Widget::on_unrealize();
}

void rise::svg_widget::get_preferred_width_vfunc(int &_minimum_width, int &_natural_width) const
{
    auto *root = doc.get_root_node();
    if(root) _minimum_width = _natural_width = std::ceil(std::atof(root->get_attribute_value("width").c_str()));
    else Gtk::Widget::get_preferred_width_vfunc(_minimum_width, _natural_width);
}

void rise::svg_widget::get_preferred_height_vfunc(int &_minimum_height, int &_natural_height) const
{
    auto *root = doc.get_root_node();
    if(root) _minimum_height = _natural_height = std::ceil(std::atof(root->get_attribute_value("height").c_str()));
    else Gtk::Widget::get_preferred_height_vfunc(_minimum_height, _natural_height);
}

void rise::svg_widget::on_size_allocate(Gtk::Allocation &_allocation)
{
    set_allocation(_allocation);
    if(window) window->move_resize(_allocation.get_x(),
				   _allocation.get_y(),
				   _allocation.get_width(),
				   _allocation.get_height());
}

bool rise::svg_widget::on_draw(Cairo::RefPtr<Cairo::Context> const &_cr)
{
    Gtk::Widget::on_draw(_cr);
    doc.draw(_cr);
    return false;
}

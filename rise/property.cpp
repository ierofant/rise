#include <rise/property.hpp>

rise::property_base::property_base(rise::style &_style, Glib::ustring const &_name)
    : style(_style),
      name(_name)
{

}

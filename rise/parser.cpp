#include <rise/parser.hpp>

rise::parser::parser(document &_doc)
    : doc(_doc)
{

}

void rise::parser::on_start_element(const Glib::ustring &_name,
                    		    const AttributeList &_properties)
{

}

void rise::parser::on_end_element(const Glib::ustring &_name)
{
    Glib::ustring prefix, name = _name;
    Glib::ustring::size_type pos = _name.find(':');
    if(pos != Glib::ustring::npos)
    {
	prefix = _name.substr(0, pos);
	name = _name.substr(pos + 1);
    }

}

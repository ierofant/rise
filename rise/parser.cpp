#include <rise/parser.hpp>

rise::parser::parser(document &_doc)
    : doc(_doc)
{

}

#include <iostream>
void rise::parser::on_start_element(const Glib::ustring &_name,
                    		    const AttributeList &_attributes)
{
    Glib::ustring prefix, name = _name;
    auto pos = _name.find(':');
    if(pos != Glib::ustring::npos)
    {
	prefix = _name.substr(0, pos);
	name = _name.substr(pos + 1);
    }

    auto *el = doc.get_root_node();
    if(!el) el = doc.create_root_node();
    else el = context.top()->add_child(name, prefix);
    context.push(el);

    for(auto itr = _attributes.begin(); itr != _attributes.end(); ++itr)
    {
	Glib::ustring name = itr->name;
	Glib::ustring value = itr->value;
	auto pos = name.find(':');
	if(pos == Glib::ustring::npos)
	{
	    if(name == "xmlns") el->set_namespace_declaration(value);
	    else el->set_attribute(name, value);
	}
	else
	{
	    Glib::ustring prefix = name.substr(0, pos);
	    Glib::ustring suffix = name.substr(pos + 1);
	    if(prefix == "xmlns") el->set_namespace_declaration(value, suffix);
	    else el->set_attribute(suffix, value, prefix);
	}
    }
}

void rise::parser::on_end_element(const Glib::ustring &_name)
{
    context.pop();
}

void rise::parser::on_comment(Glib::ustring const &_comment)
{

}

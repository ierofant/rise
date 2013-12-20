#ifndef RISE_ELEMENT_HPP_INCLUDED
#define RISE_ELEMENT_HPP_INCLUDED

#include <libxml++/nodes/element.h>

namespace rise
{
    class element : protected xmlpp::Element
    {
	public:
	    element(_xmlNode *_node);
	    virtual ~element() = default;
    };
}

#endif //RISE_ELEMENT_HPP_INCLUDED

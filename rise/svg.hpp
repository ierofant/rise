#ifndef RISE_SVG_HPP_INCLUDED
#define RISE_SVG_HPP_INCLUDED

#include <rise/element.hpp>

namespace rise
{
    class svg : public element
    {
	public:
	    svg(_xmlNode *_node);
	    virtual ~svg() = default;
    };
}

#endif //RISE_SVG_HPP_INCLUDED

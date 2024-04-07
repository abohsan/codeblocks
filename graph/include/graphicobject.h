#ifndef GRAPHICOBJECT_H_INCLUDED
#define GRAPHICOBJECT_H_INCLUDED

#include <wx/wx.h>

struct GraphicObject
{
    wxRect2DDouble rect;
    wxColor color;
    wxString text;
    wxAffineMatrix2D transform;
};

#endif // GRAPHICOBJECT_H_INCLUDED

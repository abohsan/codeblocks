#ifndef GRAPHICOBJECT_H_INCLUDED
#define GRAPHICOBJECT_H_INCLUDED

#include <wx/wx.h>


struct GraphicObject {
    static int nextId; // Declaration of a static member
    int id;
    wxRect2DDouble rect;
    wxColor color;
    wxString text;
    wxString objectType;
    int connectedToId;
    wxPoint postion;
    wxAffineMatrix2D transform;

    GraphicObject() {
        id = getNextId();
    }

    GraphicObject(int specifiedId) {
        if (specifiedId != 0) {
            id = specifiedId;
        } else {
            id = getNextId();
        }
    }

    static int getNextId() {
        static int currentId = 0;
        return ++currentId;
    }
};
#endif // GRAPHICOBJECT_H_INCLUDED

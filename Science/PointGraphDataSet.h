// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_POINT_GRAPH_DATA_SET_H_
#define _OE_POINT_GRAPH_DATA_SET_H_

#include "IDataSet.h"
#include <vector>

namespace OpenEngine {
namespace Science {
/**
 * Short description.
 *
 * @class PointGraphDataSet PointGraphDataSet.h ons/Plotting/Science/PointGraphDataSet.h
 */
class PointGraphDataSet : public IDataSet {
private:

    unsigned int resolution;
    std::vector<float>* data;
    float sx,ex;
public:
    PointGraphDataSet(unsigned int resolution, float sx, float ex); 
    virtual ~PointGraphDataSet();
    float ValueAtPoint(float x);
    void SetValue(float x, float y);
};

} // NS Science
} // NS OpenEngine

#endif // _OE_POINT_GRAPH_DATA_SET_H_

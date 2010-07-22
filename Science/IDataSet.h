// Data Set for plot
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_I_DATA_SET_H_
#define _OE_I_DATA_SET_H_

#include <Math/Vector.h>

namespace OpenEngine {
namespace Science {

using namespace Math;

/**
 * Short description.
 *
 * @class IDataSet IDataSet.h ons/Plotting/Science/IDataSet.h
 */
class IDataSet {
private:
    Vector<3,float> color;
public:
    IDataSet() : color(1,0,0) {}
    Vector<3,float> GetColor() { return color; }


    virtual float ValueAtPoint(float x) =0;
};

} // NS Science
} // NS OpenEngine

#endif // _OE_I_DATA_SET_H_

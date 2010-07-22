// Plot
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_PLOT_H_
#define _OE_PLOT_H_

#include <vector>
#include <Math/Vector.h>
#include <Resources/EmptyTextureResource.h>

namespace OpenEngine {
namespace Science {

using namespace Math;
using namespace Resources;

class IDataSet;


/**
 * Short description.
 *
 * @class Plot Plot.h ons/Plotting/Science/Plot.h
 */
class Plot {
private:
    std::vector<IDataSet*> datasets;
    
    Vector<2,float> xaxe;
    Vector<2,float> yaxe;
public:
    Plot(Vector<2,float> xaxe, Vector<2,float> yaxe);
    
    bool RenderInEmptyTexture(EmptyTextureResourcePtr tex);
};

} // NS Science
} // NS OpenEngine

#endif // _OE_PLOT_H_

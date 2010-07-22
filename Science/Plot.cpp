#include "Plot.h"
#include <Logging/Logger.h>
#include "IDataSet.h"
#include <algorithm>


namespace OpenEngine {
namespace Science {

using namespace Math;
using namespace Resources;
using namespace std;

Plot::Plot(Vector<2,float> xaxe, Vector<2,float> yaxe)
    : xaxe(xaxe)
    , yaxe(yaxe) {
    
}

void Plot::AddDataSet(IDataSet* s) {
    datasets.push_back(s);
}

bool Plot::RenderInEmptyTexture(EmptyTextureResourcePtr tex) {
    unsigned int w = tex->GetWidth();
    unsigned int h = tex->GetHeight();

    if (tex->GetChannels() < 3) {
        logger.error << "tex must be at least 3 channel" << logger.end;
        return false;
    }

    for (unsigned int x=0;x<w;x++) {
        for (unsigned int y=0;y<h;y++) {
            (*tex)(x,y,0) = 255;
            (*tex)(x,y,1) = 255;
            (*tex)(x,y,2) = 255;
        }
    }


    for (unsigned int x=0;x<w;x++) {        
        // create a index between 0 and 1
        float dx = x/float(w);

        // compute which point on the axies are here
        float xp = xaxe[0] + dx*(xaxe[1] - xaxe[0]);

        for (list<IDataSet*>::iterator itr = datasets.begin();
             itr != datasets.end();
             itr++) {
            IDataSet* set = *itr;

            float yp = set->ValueAtPoint(xp);

            float dy = (yp - yaxe[0]) / (yaxe[1] - yaxe[0]);

            unsigned int y = h*dy;
            if (y < h) {            
                (*tex)(x,y,0) = 255*set->GetColor()[0];
                (*tex)(x,y,1) = 255*set->GetColor()[1];
                (*tex)(x,y,2) = 255*set->GetColor()[2];
            }
        }
    }

    return true;
}

}
}

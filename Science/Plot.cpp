#include "Plot.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Science {

using namespace Math;
using namespace Resources;
using namespace std;

Plot::Plot(Vector<2,float> xaxe, Vector<2,float> yaxe)
    : xaxe(xaxe)
    , yaxe(yaxe) {
    
}

bool Plot::RenderInEmptyTexture(EmptyTextureResourcePtr tex) {
    unsigned int w = tex->GetWidth();
    unsigned int h = tex->GetHeight();

    if (tex->GetChannels() < 3) {
        logger.error << "tex must be at least 3 channel" << logger.end;
        return false;
    }

    for (int x=0;x<w;x++) {
        for (int y=0;y<h;y++) {
            
            (*tex)(x,y,0) = x;
            (*tex)(x,y,1) = y;
            (*tex)(x,y,2) = 0;

        }
    }

}

}
}

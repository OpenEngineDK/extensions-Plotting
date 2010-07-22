#include "PointGraphDataSet.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Science {

using namespace std;

PointGraphDataSet::PointGraphDataSet(unsigned int resolution, float sx, float ex)
    : IDataSet()
    , resolution(resolution)
    , data(new vector<float>(resolution))
    , sx(sx)
    , ex(ex)  {
    
}

PointGraphDataSet::~PointGraphDataSet() {
    delete data;
}

float PointGraphDataSet::ValueAtPoint(float x) {
    if (x >= sx && x <= ex) {
        float dx = (x - sx) / (ex - sx);
        unsigned int idx = dx*resolution;
        return (*data)[idx];
    }
    
    return 0;
}

void PointGraphDataSet::SetValue(float x, float y) {
    if (x >= sx && x <= ex) {
        float dx = (x - sx) / (ex - sx);
        unsigned int idx = dx*resolution;
        (*data)[idx] = y;
    }
}

}
}

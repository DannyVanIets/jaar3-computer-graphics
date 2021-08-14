#include "Animate_ScaleHeightAndReset.h"

Animate_ScaleHeightAndReset::Animate_ScaleHeightAndReset(float howMuchSmaller, float scaleHowMuch)
{
    HowMuchSmaller = howMuchSmaller;
    ScaleHowMuch = scaleHowMuch;
}

glm::mat4 Animate_ScaleHeightAndReset::DoAnimation(glm::mat4 model)
{
    if (FirstTime) {
        FirstTime = false;
        OriginalHeightValue = model[1].y;
    }
    if (OriginalHeightValue - HowMuchSmaller >= model[1].y) {
        model[1].y = OriginalHeightValue;
        return model;
    }
    return DoScaling(model, 1.0, 0.999, 1.0);
}

#include "Animate_GoUpAndReset.h"

Animate_GoUpAndReset::Animate_GoUpAndReset(float howMuchHigher)
{
    HowMuchHigher = howMuchHigher;
}

glm::mat4 Animate_GoUpAndReset::DoAnimation(glm::mat4 model)
{
    if (FirstTime) {
        FirstTime = false;
        OriginalYValue = model[3].y;
    }
    if (OriginalYValue + HowMuchHigher <= model[3].y) {
        return DoTranslation(model, 0.0, -HowMuchHigher, 0.0);
    }
    else {
        return DoTranslation(model, 0.0, 0.01, 0.0);
    }
}

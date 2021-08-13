#include "Animate_GoUpAndThenDown.h"

Animate_GoUpAndThenDown::Animate_GoUpAndThenDown(float howMuchHigher)
{
    HowMuchHigher = howMuchHigher;
}

glm::mat4 Animate_GoUpAndThenDown::DoAnimation(glm::mat4 model)
{
    if (FirstTime) {
        FirstTime = false;
        OriginalYValue = model[3].y;
    }
    if (OriginalYValue + HowMuchHigher <= model[3].y && GoingUp) {
        Y = -Y;
        GoingUp = false;
    }
    if (OriginalYValue >= model[3].y && !GoingUp) {
        Y = -Y;
        GoingUp = true;
    }
    return DoTranslation(model, 0.0, Y, 0.0);
}

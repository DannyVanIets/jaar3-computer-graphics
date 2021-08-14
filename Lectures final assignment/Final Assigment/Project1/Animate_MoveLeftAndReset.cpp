#include "Animate_MoveLeftAndReset.h"

Animate_MoveLeftAndReset::Animate_MoveLeftAndReset(float howMuchToTheLeft)
{
    HowMuchToTheLeft = howMuchToTheLeft;
}

glm::mat4 Animate_MoveLeftAndReset::DoAnimation(glm::mat4 model)
{
    if (FirstTime) {
        FirstTime = false;
        OriginalXValue = model[3].x;
    }
    if (OriginalXValue + HowMuchToTheLeft >= model[3].x) 
    {
        model[3].x = OriginalXValue;
        return model;
    }
    else 
    {
        return DoTranslation(model, -0.1, 0.0, 0.0);
    }
}

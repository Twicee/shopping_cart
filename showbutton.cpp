#include "showbutton.h"

void showButton::changeText(bool visible){
    if (visible == true)
        setText("Hide Cart");
    else
        setText("Show Cart");
}

void showButton::changeText(){
    setText("Show Cart");
}

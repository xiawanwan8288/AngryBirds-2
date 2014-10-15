//
//  SlingShot.cpp
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#include "SlingShot.h"
#include <OpenGLES/ES1/gl.h>
SlingShot::SlingShot()
{
    this->initWithFile("CloseNormal.png");
}
void SlingShot::draw()
{
    // 要实现真正的画线
    ccDrawColor4B(255, 0, 0, 255);
    glLineWidth(3.0f);
    glEnable(GL_LINE_SMOOTH);
    ccDrawLine(_startPoint1, _endPoint);
    ccDrawLine(_startPoint2, _endPoint);
}
#include "RendererLayout.hpp"

RendererLayout::RendererLayout()
{
    uWidth      = 0;
    uHeight     = 0;
}

void RendererLayout::WindowResized(unsigned uWidth, unsigned uHeight)
{
    this->uWidth    = uWidth;
    this->uHeight   = uHeight;
}

unsigned RendererLayout::ClientWidth()
{
    return uWidth;
}

unsigned RendererLayout::ClientHeight()
{
    return uHeight;
}

#ifndef RENDERER_LAYOUT_HPP_INCLUDED
#define RENDERER_LAYOUT_HPP_INCLUDED

class RendererLayout
{
public:
                RendererLayout();

    void        WindowResized(unsigned uWidth, unsigned uHeight);

    unsigned    ClientWidth();

    unsigned    ClientHeight();

private:
    unsigned    uWidth, uHeight;
};

#endif

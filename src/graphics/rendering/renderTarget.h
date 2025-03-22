#pragma once

#include <cfmath.h>

#include <rendering/drawable.h>
#include <rendering/batchRenderer.h>

namespace cf {
    class RenderTarget {
    public:
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual void clear() = 0;
        virtual void resize(int width, int height) = 0;

        virtual void draw(Drawable& drawable) = 0;
        virtual void render() = 0;
        
        ~RenderTarget() = default;
    protected:
        BatchRenderer renderer;
    };
}
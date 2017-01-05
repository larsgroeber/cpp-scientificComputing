#ifndef ROCHE_LIMIT_GRAPHIC_H
#define ROCHE_LIMIT_GRAPHIC_H

#include "../include/Constants.h"

#ifdef GRAPHICS

#include <jaogll/sprite.h>
#include <jaogll/window.h>
#include <jaogll/timing.h>
#include <jaogll/camera2D.h>
#include <jaogll/sprite_batch.h>
#include <jaogll/input_manager.h>
#include <jaogll/glsl_compiler.h>

#include <vector>
#include "../helper/include/Vector.h"

namespace LH
{
    enum class State {PLAY, QUIT};

    /**
     * \brief Class to draw the simulation using the opengl library jaogll.
     */
    class Graphic
    {
    public:
        Graphic ( unsigned w_width, unsigned w_height, unsigned fps );

        void set_sprites ( const std::vector<std::tuple<LH::Vector,float,std::string>>& _sprites );

        void set_viewing_pos ( LH::Vector pos );

        void set_viewing_scale ( float scale );

        void process_input ();

        void draw ();

        State get_state () const;

    private:
        void init_shaders ();

        State _state;

        JOGL::Window _window;

        /** Screen dimensions */
        const unsigned _w_width;
        const unsigned _w_height;

        const unsigned _max_fps;

        std::vector<std::tuple<LH::Vector,float,std::string>> _sprites;

        JOGL::Fps_Limiter _fpsLimiter;

        JOGL::Camera2D _camera;

        JOGL::Sprite_Batch _spriteBatch;

        JOGL::Input_Manager _inputManager;

        JOGL::GLSLCompiler* _colorProgram;
    };


}

#endif

#endif //ROCHE_LIMIT_GRAPHIC_H

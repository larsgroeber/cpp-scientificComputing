#include "../include/graphic.h"

#ifdef GRAPHICS

#include <SDL2/SDL.h>
#include <jaogll/jaogll.h>
#include <jaogll/logger.h>

JOGL::LogLevel JOGL::Logger::current_log_level = JOGL::LogLevel::LOG_DEBUG;

LH::Graphic::Graphic ( unsigned w_width, unsigned w_height, unsigned fps )
    : _w_width ( w_width )
      , _w_height ( w_height )
      , _max_fps ( fps )
      , _state ( LH::State::PLAY )
{
    JOGL::init();

    _window.create( "Roche Limit", _w_width, _w_height, 0 );

    _window.set_clear_color( JOGL::Color ( 200, 200, 200, 255 ) );

    init_shaders();

    _camera.init( w_width, w_height );

    _spriteBatch.init();

    _fpsLimiter.init( _max_fps );
}

void LH::Graphic::init_shaders ()
{
    _colorProgram = new JOGL::GLSLCompiler;
    _colorProgram->compileShaders( "./graphics/shaders/colorShading.vert", "./graphics/shaders/colorShading.frag" );
    _colorProgram->addAttribute( "vertexPosition" );
    _colorProgram->addAttribute( "vertexColor" );
    _colorProgram->addAttribute( "vertexUV" );
    _colorProgram->linkShaders();
}

void LH::Graphic::process_input ()
{
    SDL_Event event;

    const float CAMERA_SPEED = 1.0f;
    const float SCALE_SPEED = .01f;
    static bool shot = false;

    while ( SDL_PollEvent( &event ) )
    {
        switch ( event.type )
        {
            case SDL_QUIT:
                _state = LH::State::QUIT;
                break;
            case SDL_KEYDOWN:
                switch ( event.key.keysym.sym )
                {
                    case SDLK_w:
                        _camera.setPosition( _camera.getPosition() + glm::vec2 ( 0, 1 ) * CAMERA_SPEED );
                        break;
                    case SDLK_s:
                        _camera.setPosition( _camera.getPosition() + glm::vec2 ( 0, -1 ) * CAMERA_SPEED );
                        break;
                    case SDLK_a:
                        _camera.setPosition( _camera.getPosition() + glm::vec2 ( -1, 0 ) * CAMERA_SPEED );
                        break;
                    case SDLK_d:
                        _camera.setPosition( _camera.getPosition() + glm::vec2 ( 1, 0 ) * CAMERA_SPEED );
                        break;
                    case SDLK_q:
                        _camera.setScale( _camera.getScale() + SCALE_SPEED );
                        break;
                    case SDLK_e:
                        _camera.setScale( _camera.getScale() - SCALE_SPEED );
                        break;
                }
                break;
        }
    }
}

void LH::Graphic::draw ()
{
    process_input();

    _camera.update();

    _colorProgram->use();

    _fpsLimiter.limit();

    // set texture
    glActiveTexture( GL_TEXTURE0 );
    GLint textureLocation = _colorProgram->get_uniformLocation( "mySampler" );
    glUniform1i( textureLocation, 0 );

    // set camera matrix
    GLint pLocation = _colorProgram->get_uniformLocation( "P" );
    glm::mat4 cameraMatrix = _camera.getCameraMatrix();
    glUniformMatrix4fv( pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]) );

    _spriteBatch.begin();

    for ( auto&& b : _sprites )
    {
        _spriteBatch.add_sprite( JOGL::Sprite (
                std::get<0>(b).x, std::get<0>(b).y   // pos
                , std::get<1>(b), std::get<1>(b)     // width, height
                , JOGL::Color ( 255, 255, 255, 255 ) // color
                , std::get<2>(b)                     // file
                , 0                                  // depth
        ) );
    }

    _spriteBatch.end();

    _spriteBatch.render_batch();

    _colorProgram->unuse();

    _window.swap();
}

void LH::Graphic::set_sprites ( const std::vector<std::tuple<LH::Vector,float,std::string>>& _sprites )
{
    Graphic::_sprites = _sprites;
}

LH::State LH::Graphic::get_state () const
{
    return _state;
}

#endif
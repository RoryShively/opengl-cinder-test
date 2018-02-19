#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "ParticleController.h"

//#include "cinder/ImageIo.h"
//#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#include "cinder/Log.h"

class TestAppApp : public App {
private:
    Channel32f              mImgChannel;
    ParticleController      mParticleController;
    vec2                    mMouseLoc;
    
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void mouseMove( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
    void update() override;
    void draw() override;

    void enableFileLogging();
};

void TestAppApp::setup()
{
    // Load background image
    auto img = loadImage( loadAsset( "tiger.jpg" ) );
    mImgChannel = Channel32f( img );
//    mTex = gl::Texture2d::create( img );
    
    // Load particles
    mParticleController = ParticleController( 1000, 600 );
}

void TestAppApp::enableFileLogging()
{
    //! This call will append log messages to the file `cinder.log` in the folder `/tmp/logging`.
    //! If the folder path `/tmp/logging` does not exist, it will be created for you.
    
    log::makeLogger<log::LoggerFile>( "/tmp/logging/cinder.log", true );
}

void TestAppApp::mouseDown( MouseEvent event )
{
//    CI_LOG_D( "something" );
    char message[10] = "message";
    cout << message << endl;
}

void TestAppApp::mouseMove( MouseEvent event ) {
    mMouseLoc = event.getPos();
//    cout << mMouseLoc << endl;
}

void TestAppApp::mouseDrag( MouseEvent event ) {
    mouseMove( event );
}

void TestAppApp::update()
{
    mParticleController.update( mImgChannel, mMouseLoc );
//    mParticleController.addParticles( 1 );
}

void TestAppApp::draw()
{
    gl::clear();
//    gl::draw( mTex, getWindowBounds() );
    mParticleController.draw();
    
//    float es = getElapsedSeconds();
//
//    float x = ((cos( es ) * 60.0f) + getWindowWidth() / 2) + sin( es );
//    float y = (sin( es ) * 60.0f) + getWindowHeight() / 2 + cos ( es );
//    float s = abs( sin( es ) ) * 10.0f;
//    CI_LOG_D( s );
//
//    gl::drawSolidCircle( vec2( x, y ), 50.0f, s );
}

CINDER_APP( TestAppApp, RendererGl, [](App::Settings *settings) {
    settings->setWindowSize( 1000, 600 );
})

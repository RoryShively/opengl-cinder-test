#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
//#include “cinder/gl/Batch.h”

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
    
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;

    void enableFileLogging();
};

void TestAppApp::setup()
{
    // Create grey scale channel from image
    auto img = loadImage( loadAsset( "tiger.jpg" ) );
    mImgChannel = Channel32f( img );
    
    // Load particles
    mParticleController = ParticleController( 800, 600 );
}

void TestAppApp::enableFileLogging()
{
    //! This call will append log messages to the file `cinder.log` in the folder `/tmp/logging`.
    //! If the folder path `/tmp/logging` does not exist, it will be created for you.
    
    log::makeLogger<log::LoggerFile>( "/tmp/logging/cinder.log", true );
}

void TestAppApp::mouseDown( MouseEvent event ) {}

void TestAppApp::update()
{
//    mParticleController.update( mImgChannel );
}

void TestAppApp::draw()
{
    gl::clear();
    mParticleController.draw();
}

CINDER_APP( TestAppApp, RendererGl, [](App::Settings *settings) {
    settings->setWindowSize( 800, 600 );
} )

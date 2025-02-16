#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreCameraMan.h>

class BasicTutorial1 : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:
    BasicTutorial1() : OgreBites::ApplicationContext("OgreTutorialApp") {}
    
    void setup() override
    {
        // Do not forget to call the base first
        OgreBites::ApplicationContext::setup();
        
        // Register for input events
        addInputListener(this);
        
        // Get a pointer to the already created root
        Ogre::Root* root = getRoot();
        Ogre::SceneManager* scnMgr = root->createSceneManager();
        
        // Register our scene with the RTSS
        Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
        shadergen->addSceneManager(scnMgr);
        
        // Create a camera
        Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
        Ogre::Camera* cam = scnMgr->createCamera("myCam");
        cam->setNearClipDistance(5);
        cam->setAutoAspectRatio(true);
        camNode->attachObject(cam);
        
        // Create a viewport
        getRenderWindow()->addViewport(cam);
        
        // Create a light
        Ogre::Light* light = scnMgr->createLight("MainLight");
        Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
        lightNode->setPosition(0, 10, 15);
        lightNode->attachObject(light);
        
        // Create an Entity
        Ogre::Entity* ogreEntity = scnMgr->createEntity("ogrehead.mesh");
        Ogre::SceneNode* ogreNode = scnMgr->getRootSceneNode()->createChildSceneNode();
        ogreNode->attachObject(ogreEntity);
        
        // Display FPS and latency
        Ogre::OverlaySystem* overlaySystem = new Ogre::OverlaySystem();
        scnMgr->addRenderQueueListener(overlaySystem);
        Ogre::OverlayManager& overlayManager = Ogre::OverlayManager::getSingleton();
        Ogre::Overlay* overlay = overlayManager.create("OverlayName");
        Ogre::TextAreaOverlayElement* textArea = static_cast<Ogre::TextAreaOverlayElement*>(overlayManager.createOverlayElement("TextArea", "TextAreaName"));
        textArea->setCaption("FPS: 0\nLatency: 0 ms");
        textArea->setCharHeight(0.03);
        textArea->setColour(Ogre::ColourValue::White);
        overlay->add2D(textArea);
        overlay->show();
        
        root->addFrameListener(new Ogre::FrameListener());
    }
}

int main(int argc, char** argv)
{
    BasicTutorial1 app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();
    return 0;
}

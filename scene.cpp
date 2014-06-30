#include "scene.h"
#include "scenetranslation.h"

Scene::Scene() {
    //create new rootNode (the one node to rule them all... and so on) for scene
    _parentNode = new SceneTranslation();
}

SceneNode* Scene::getParentNode(){
    return _parentNode;
}

SceneNode* Scene::getNode(int nodeId) {
    return findNode(dynamic_cast<SceneTransformation*>(_parentNode), nodeId);
}

SceneNode* Scene::findNode(SceneTransformation* transformNode, int nodeId) {
    //go through the composite structure
    SceneNode* currentNode;
    for(unsigned int i = 0; i < transformNode->getChildNodes().size(); i++) {
        currentNode = transformNode->getChildNodes().at(i);

        //recursive call if childNode at i is a SceneTransformation, else return current if id match
        if(dynamic_cast<SceneTransformation*>(currentNode)){

            //if findNode recursive did not return 0
            if(SceneNode* foundNode = findNode(dynamic_cast<SceneTransformation*>(currentNode), nodeId)){
                return foundNode;
            }
        } else {
            if(currentNode->getNodeId() == nodeId){
                return currentNode;
            }
        }
    }

    //did not find node
    return 0;
}

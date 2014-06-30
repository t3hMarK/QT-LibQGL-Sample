#include "scenenode.h"
#include <sstream>

SceneNode::SceneNode() {

}

SceneNode::SceneNode(SceneNode* parentNode){
    _parentNode = parentNode;
}

void SceneNode::setNodeId(int id){
    _nodeId = id;
}

void SceneNode::setParentNode(SceneNode *parentNode){
    _parentNode = parentNode;
}

int SceneNode::getNodeId(){
    return _nodeId;
}

SceneNode* SceneNode::getParentNode(){
    return _parentNode;
}

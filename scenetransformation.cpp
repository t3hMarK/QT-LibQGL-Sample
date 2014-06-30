#include "scenetransformation.h"

SceneTransformation::SceneTransformation() {

}

SceneTransformation::SceneTransformation(SceneNode* parentNode) : SceneNode(parentNode) {

}

void SceneTransformation::addChildNode(SceneNode* childNode) {
    //if childNodes vector is instanciated
    if(&_childNodes){
        _childNodes.push_back(childNode);
    }
}

void SceneTransformation::removeChildNode(SceneNode* childNode) {
    //if childNodes vector is instanciated
    if(&_childNodes){

        //find childNode
        for(unsigned int i = 0; i < _childNodes.size(); i++){

            //remove childNode
            if(_childNodes.at(i) == childNode){
                _childNodes.erase(_childNodes.begin() + i);
            }
        }
    }
}

void SceneTransformation::swapChildNode(SceneNode* oldChildNode, SceneNode* newChildNode) {
    //if childNodes vector is instanciated
    if(&_childNodes){

        //find childNode
        for(unsigned int i = 0; i < _childNodes.size(); i++){

            //remove childNode
            if(_childNodes.at(i) == oldChildNode){

                /*
                 *  We remove the oldNode and insert the newNode at the end of the vector, this is more efficient O(1) instead of O(N)
                 *  The _childNodes vector (which reprensent the SceneGraph) is not sensitive to position
                 *  example:    if a SceneGraph contains 3 elements and we "swap" the 2nd element for another
                 *              then the new element will simply be drawn last without any impact on other
                 *              element at the same level
                 */
                _childNodes.erase(_childNodes.begin() + i);
                _childNodes.push_back(newChildNode);
            }
        }
    }
}

std::vector<SceneNode*> SceneTransformation::getChildNodes(){
    return _childNodes;
}

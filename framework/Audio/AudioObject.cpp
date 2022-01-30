#include "AudioObject.h"

AudioObject::AudioObject(std::string path, bool isloop) :filePath(path), loop(isloop){}

std::string AudioObject::getPath() const {return filePath;}

bool AudioObject::isLoop() const {return loop;}
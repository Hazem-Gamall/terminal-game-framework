#ifndef AUDIOOBJECT
#define AUDIOOBJECT

#include <string>

class AudioObject{
public:
    AudioObject(std::string path, bool isloop);
    std::string getPath() const;
    bool isLoop() const;
private:
    std::string filePath;
    bool loop;
};

#endif
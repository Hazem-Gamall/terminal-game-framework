#ifndef AUDIOHANDLER
#define AUDIOHANDLER

#include "miniaudio.h"
#include <string>
#include <map>
#include "AudioObject.h"

class AudioHandler{
public:
    static AudioHandler* getInstance(){
        if(instance == 0){
            instance = new AudioHandler();
        }
        return instance;
    }
    
    bool play(std::string);
    bool stop();
    void addAudio(std::string, AudioObject*);
    void removeAudio(std::string);
    void clean();
private:
    static AudioHandler* instance;
    AudioHandler();
    std::map<std::string, AudioObject*> audioFiles;
    ma_device device;
    ma_device_config deviceConfig;
    ma_decoder decoder;
    bool isRunning;
    static void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
    static void loop_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
};

#endif
#include "AudioHandler.h"

AudioHandler* AudioHandler::instance = 0;

AudioHandler::AudioHandler(){
    isRunning = false;
}

bool AudioHandler::play(std::string id){
    auto it = audioFiles.find(id);
    if(it == audioFiles.end()){
        printf("Non registered ID");
        return false;
    }
    if(isRunning)
        stop();
    if(ma_decoder_init_file(audioFiles[id]->getPath().c_str(), NULL, &decoder) != MA_SUCCESS){
        printf("Could not load file");
        return false;
    }

    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate        = decoder.outputSampleRate;
    deviceConfig.dataCallback = audioFiles[id]->isLoop()? loop_data_callback: data_callback;
    deviceConfig.pUserData         = &decoder;


    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        return false;
    }

    if(ma_device_start(&device) != MA_SUCCESS){
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return false;
    }

    isRunning = true;
    return true;
}

bool AudioHandler::stop(){
    if(ma_device_stop(&device) != MA_SUCCESS){
        printf("Failed to stop playback device\n");
        return false;
    }
    isRunning = false;
    return true;
}

void AudioHandler::addAudio(std::string id, AudioObject* audioFile){
    audioFiles[id] = audioFile;
}

void AudioHandler::removeAudio(std::string id){
    audioFiles.erase(id);
}

void AudioHandler::loop_data_callback(ma_device* pDevice, void* pOutput,
 const void* pInput, ma_uint32 frameCount){

    ma_bool32 isLooping = MA_TRUE;

    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    ma_data_source_read_pcm_frames(pDecoder, pOutput, frameCount, NULL, isLooping);


    (void)pInput;

}

void AudioHandler::data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    // ma_bool32 isLooping = MA_TRUE;

    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount);
    // ma_data_source_read_pcm_frames(pDecoder, pOutput, frameCount, NULL, isLooping);


    (void)pInput;
}

void AudioHandler::clean(){
    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
}
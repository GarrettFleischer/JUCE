#pragma once

#include "juce_audio_plugin_client/juce_audio_plugin_client.h"


namespace juce
{
    class Juce4UnityAudioProcessor : public AudioProcessor
    {
    public:
        Juce4UnityAudioProcessor(const BusesProperties& ioLayouts) : AudioProcessor(ioLayouts){}

        virtual int loadInstrument(const String& sfzFilePath) = 0;
        virtual void unloadInstrument(const String& sfzFilePath) = 0;
        virtual void clearInstruments() = 0;
    
        virtual void setInstrument(const String& sfzFilePath) = 0;
    
        virtual void noteOn(int channel, int midi, float velocity) = 0;
        virtual void noteOff(int channel, int midi) = 0;
        virtual void allNotesOff(int channel) = 0;
    };
}

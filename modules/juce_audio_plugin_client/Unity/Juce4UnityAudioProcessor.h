#pragma once

#include "juce_audio_plugin_client/juce_audio_plugin_client.h"


namespace juce
{
    using ExternalMidiInputCallback = void(*)(int id, uint8, uint8, uint8);

    class Juce4UnityAudioProcessor : public AudioProcessor
    {
    public:
        Juce4UnityAudioProcessor(const BusesProperties& ioLayouts) : AudioProcessor(ioLayouts)
        {
        }

        // Sampler
        virtual int loadInstrument(const String& sfzFilePath) = 0;
        virtual void unloadInstrument(const String& sfzFilePath) = 0;
        virtual void clearInstruments() = 0;

        virtual void setInstrument(const String& sfzFilePath) = 0;

        virtual void noteOn(int channel, int midi, float velocity) = 0;
        virtual void noteOff(int channel, int midi) = 0;
        virtual void allNotesOff(int channel) = 0;

        // Devices
        virtual void registerMidiCallback(ExternalMidiInputCallback callback) = 0;

        virtual void refreshDevices() = 0;

        [[nodiscard]] virtual int deviceCount() const = 0;

        [[nodiscard]] virtual bool deviceIsEnabled(int id, bool input) const = 0;

        virtual bool setDeviceEnabled(int id, bool input, bool enabled) = 0;

        [[nodiscard]] virtual bool deviceHasInput(int id) const = 0;
        [[nodiscard]] virtual bool deviceHasOutput(int id) const = 0;

        virtual void getDeviceName(int id, char* str, int strlen) const = 0;
        virtual void getDeviceIdentifier(int id, char* str, int strlen) const = 0;

        virtual void sendMessage(uint8 byte1, uint8 byte2, uint8 byte3, int id = -1) const = 0;
        virtual void sendMessage(uint8 byte1, uint8 byte2, int id = -1) const = 0;
        virtual void sendMessage(uint8 byte1, int id = -1) const = 0;

        virtual void sendSysEx(const void* data, int dataSize, int id = -1) const = 0;

        virtual void sendNoteOn(int channel, int midi, float velocity, int id = -1) const = 0;
        virtual void sendNoteOff(int channel, int midi, int id = -1) const = 0;

        virtual void sendAllNotesOff(int channel, int id = -1) const = 0;
        virtual void sendAllSoundOff(int channel, int id = -1) const = 0;
    };
}

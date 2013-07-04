#ifndef SOUND_HPP
#define SOUND_HPP

class SoundService;

#include "Context.hpp"
#include "Resource.hpp"
#include "Types.hpp"

namespace Core
{
    class Sound
    {
    public:
        Sound(const char* pPath);
        ~Sound();

        const char* GetPath();

        Status Load();
        Status Unload();

        uint8_t* GetPCMData();
        off_t GetPCMLength();

    private:
        friend class SoundService;

    private:
        Resource* mResource;
        uint8_t* mBuffer; off_t mLength;
        char extension[4];
    };
}
#endif

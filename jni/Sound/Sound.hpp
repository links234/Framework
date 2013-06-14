#ifndef _PACKT_SOUND_HPP_
#define _PACKT_SOUND_HPP_

class SoundService;

#include "Context.hpp"
#include "Asset.hpp"
#include "Types.hpp"

namespace Core
{
    class Sound
    {
    public:
        Sound(const char* pPath);

        const char* GetPath();

        Status Load();
        Status Unload();

    private:
        friend class SoundService;

    private:
        Asset mResource;
        uint8_t* mBuffer; off_t mLength;
    };
}
#endif
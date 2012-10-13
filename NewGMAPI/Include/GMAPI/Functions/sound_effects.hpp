/* Copyright (c) 2011-2012 William Newbery
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */
//Auto-Generated File
#ifndef GMAPI_FUNCTIONS_SOUND_EFFECTS_HPP
#define GMAPI_FUNCTIONS_SOUND_EFFECTS_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void sound_effect_set(Real snd, Real effect)
    {
        call(functions[909], snd, effect);
    }
    
    inline void sound_effect_chorus(Real snd, Real wetdry, Real depth, Real feedback, Real frequency, Real wave, Real delay, Real phase)
    {
        call(functions[910], snd, wetdry, depth, feedback, frequency, wave, delay, phase);
    }
    
    inline void sound_effect_echo(Real snd, Real wetdry, Real feedback, Real leftdelay, Real rightdelay, Real pandelay)
    {
        call(functions[911], snd, wetdry, feedback, leftdelay, rightdelay, pandelay);
    }
    
    inline void sound_effect_flanger(Real snd, Real wetdry, Real depth, Real feedback, Real frequency, Real wave, Real delay, Real phase)
    {
        call(functions[912], snd, wetdry, depth, feedback, frequency, wave, delay, phase);
    }
    
    inline void sound_effect_gargle(Real snd, Real rate, Real wave)
    {
        call(functions[913], snd, rate, wave);
    }
    
    inline void sound_effect_reverb(Real snd, Real gain, Real mix, Real time, Real ratio)
    {
        call(functions[914], snd, gain, mix, time, ratio);
    }
    
    inline void sound_effect_compressor(Real snd, Real gain, Real attack, Real release, Real threshold, Real ratio, Real delay)
    {
        call(functions[915], snd, gain, attack, release, threshold, ratio, delay);
    }
    
    inline void sound_effect_equalizer(Real snd, Real center, Real bandwidth, Real gain)
    {
        call(functions[916], snd, center, bandwidth, gain);
    }
    
    ///@}
}
#endif

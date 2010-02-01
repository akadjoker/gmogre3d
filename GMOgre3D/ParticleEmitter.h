/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
                   <robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/

#ifndef GMOGRE_PARTICLE_EMITTER_H
#define GMOGRE_PARTICLE_EMITTER_H

#include "GMOgre3D.h"


GMFN double SetParticleEmitterPosition(double part_emit_ptr, double xfrom, double zfrom, double yfrom)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setPosition(ConvertFromGMAxis(xfrom, yfrom, zfrom));

   return TRUE;
}


GMFN double SetParticleEmitterDirection(double part_emit_ptr, double xto, double zto, double yto)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setDirection(ConvertFromGMAxis(xto, yto, zto));

   return TRUE;
}


GMFN double SetParticleEmitterAngle(double part_emit_ptr, double degrees)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setAngle(Ogre::Degree(degrees));

   return TRUE;
}


GMFN double SetParticleEmitterVelocity(double part_emit_ptr, double speed)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setParticleVelocity(speed);

   return TRUE;
}


GMFN double SetParticleEmitterVelocityRange(double part_emit_ptr, double min_speed, double max_speed)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setParticleVelocity(min_speed, max_speed);

   return TRUE;
}


GMFN double SetParticleEmitterEmissionRate(double part_emit_ptr, double rate)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setEmissionRate(rate);

   return TRUE;
}


GMFN double SetParticleEmitterTimeToLive(double part_emit_ptr, double ttl)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setTimeToLive(ttl);

   return TRUE;
}


GMFN double SetParticleEmitterTimeToLiveRange(double part_emit_ptr, double min_ttl, double max_ttl)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setTimeToLive(min_ttl, max_ttl);

   return TRUE;
}


GMFN double SetParticleEmitterColor(double part_emit_ptr, double color)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setColour(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)));

   return TRUE;
}


GMFN double SetParticleEmitterColorRange(double part_emit_ptr, double min_color, double max_color)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setColour(Ogre::ColourValue(GetRedFromGMColor(min_color), GetGreenFromGMColor(min_color), GetBlueFromGMColor(min_color)), Ogre::ColourValue(GetRedFromGMColor(max_color), GetGreenFromGMColor(max_color), GetBlueFromGMColor(max_color)));

   return TRUE;
}


GMFN double SetParticleEmitterStartTime(double part_emit_ptr, double start_time)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setStartTime(start_time);

   return TRUE;
}


GMFN double SetParticleEmitterDuration(double part_emit_ptr, double duration)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setDuration(duration);

   return TRUE;
}


GMFN double SetParticleEmitterDurationRange(double part_emit_ptr, double min_duration, double max_duration)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setDuration(min_duration, max_duration);

   return TRUE;
}


GMFN double SetParticleEmitterRepeatDelay(double part_emit_ptr, double delay)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setRepeatDelay(delay);

   return TRUE;
}


GMFN double SetParticleEmitterRepeatDelayRange(double part_emit_ptr, double min_delay, double max_delay)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setRepeatDelay(min_delay, max_delay);

   return TRUE;
}


GMFN double SetParticleEmitterDimensions(double part_emit_ptr, double width, double height)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setDimensions(width, height);

   return TRUE;
}


GMFN double EnableParticleEmitter(double part_emit_ptr, double enable)
{
   Ogre::ParticleEmitter *part_emit = ConvertFromGMPointer<Ogre::ParticleEmitter*>(part_emit_ptr);

   if (part_emit == NULL)
      return FALSE;

   part_emit->setEnabled((enable != 0));

   return TRUE;
}

#endif
